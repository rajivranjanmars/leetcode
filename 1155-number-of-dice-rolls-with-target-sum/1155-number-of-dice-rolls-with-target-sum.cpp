#define mod 1000000007
class Solution {
public:
       
    
    int numRollsToTarget(int d, int f, int target) {
        
        int dp[target + 1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=1;i<=d;i++){
            for(int j = target; j >= 0; j--){
                dp[j] = 0;
                for(int k = 1;k<=f;k++){
                    dp[j] += j >= k ? dp[j - k] : 0;
                    dp[j] = dp[j]%mod;
                }
            }
        }
        return dp[target];
        
    }
};
