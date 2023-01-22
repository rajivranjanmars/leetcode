class Solution {
    bool checkPalindrome(string s,int l,int r){
        while(l<=r) if(s[l++]!=s[r--]) return false;
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; vector<string> curr;
        findPartition(0,curr,ans,s);
        return ans;
    }
    
    void findPartition(int idx,vector<string> &curr, vector<vector<string>> &ans,string s){
        if(idx==s.size()) {ans.push_back(curr);return;}
        for(int i=idx;i<s.size();i++){
            if(checkPalindrome(s,idx,i)){
                curr.push_back(s.substr(idx, i - idx + 1));
                findPartition(i+1,curr,ans,s);
                curr.pop_back();
            }
        }
    }
};