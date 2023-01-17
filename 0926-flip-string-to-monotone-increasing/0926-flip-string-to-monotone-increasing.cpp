class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int dp[n][2]; 
        // dp[i][0] = min flips keeping string monotone increasing till index i with s[i] = 0
        // dp[i][1] = min flips keeping string monotone increasing till index i with s[i] = 1
        if(s[0] == '0') {
            dp[0][0] = 0;
            dp[0][1] = 1;
        } else {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = 1 + min(dp[i - 1][1], dp[i - 1][0]);
            } else {
                dp[i][0] = 1 + dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]);
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};