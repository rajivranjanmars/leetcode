class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int>v(b.size(),0);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b.size();j++){
                if(i==j)
                    continue;
                
                if(b[j]=='1')
                v[i]+=abs(i-j);
            }
        }
       return v; 
    }
};