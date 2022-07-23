class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>v;
        for(int i=0;i<=s[3]-s[0];i++){
            for(int j=0;j<=s[4]-s[1];j++){
                string a="";
               a+=s[0]+i;
                a+=(s[1]+j);
                v.push_back(a);
            }
        }
        return v;
    }
};