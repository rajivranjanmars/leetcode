class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
         int ans=0;
        sort(c.begin(),c.end());
        if(coins==0 || coins<c[0])return 0;
        for(int i=0;i<c.size();i++){
            if(c[i]<=coins){
                coins-=c[i];
                ans++;
            }
            else break;
            //cout<<coins<<endl;
        }
        return ans;
    }
};