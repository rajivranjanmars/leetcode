class Solution {
public:
    bool canConstruct(string r, string z) {
       
        map<char,int>m;
        for(int i=0;i<z.size();i++){
            m[z[i]]++;
        }
        for(int i=0;i<r.size();i++){
            m[r[i]]--;
        }
        for(auto i:m){
            if(i.second<0)
                return false;
        }
        return true;
    }
};