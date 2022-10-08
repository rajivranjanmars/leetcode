class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v(n);
        int ans=start;
        for(int i=1;i<n;i++){
            v[i]=start+2*i;
            ans=ans^v[i];
        }
       return ans;
    }
};