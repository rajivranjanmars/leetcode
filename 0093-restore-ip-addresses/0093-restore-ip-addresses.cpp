class Solution {
public:
    bool isValid(string s){
        int n = s.size();
        if(n == 0 or n > 3) return false;
        if(n > 1 and s[0] == '0') return false;
        if(stoi(s) > 255) return false;
        return true;
    }
    
    string helper(string s, int i, int j, int k){
        int n = s.size();
        string s1 = s.substr(0, i + 1);
        string s2 = s.substr(i + 1, j - i);
        string s3 = s.substr(j + 1, k - j);
        string s4 = s.substr(k + 1, n - k - 1);
        if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
            return s1 + '.' + s2 + '.' + s3 + '.' + s4;
        }
        return "";
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    string curr = helper(s, i, j, k);
                    if(curr.size() > 0) ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};