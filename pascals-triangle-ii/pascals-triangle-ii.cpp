class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>g;
        
       for(int i=0; i<=n;i++){
           vector<int>v(i+1,1);
           for(int j=1;j<(i+2)/2;j++){
              v[j]=g[i-1][j]+g[i-1][j-1];
               v[i-j]=v[j];
           }
           g.push_back(v);
       }
        return g[n];
    }
};