class Solution {
public:
    unordered_map<char,int>mp;
    bool compare(string &first,string &second){
        int m=first.size(),n=second.size();
        for(int i=0;i<min(m,n);i++){
            if(mp[first[i]]<mp[second[i]])return true;
            else if(mp[first[i]]>mp[second[i]]) return false;
        }
        if(n>=m)return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++){
            mp[order[i]]=i;
        }
        for(int i=0;i<words.size()-1;i++){
            if(!compare(words[i],words[i+1]))return false;
        }
        return true;
    }
};