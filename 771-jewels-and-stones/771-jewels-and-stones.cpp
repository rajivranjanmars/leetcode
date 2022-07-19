class Solution {
public:
    int numJewelsInStones(string j, string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int count =0;
         for(int i=0;i<j.size();i++){
            count+=m[j[i]];
        }
        return count;
    }
};