class Solution {
public:

    const int mod = 1e9 + 7;
    int dp[51][51][11];

    bool check(vector<string>& pizza, int r1, int c1, int r2, int c2){
        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }

    int f(vector<string>& pizza, int r, int c, int k){
        if(k == 0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        int n = pizza.size(), m = pizza[0].size();
        long long ans = 0;
        for(int i = r; i < n - 1; i++){
            if(check(pizza, r, c, i, m - 1) and check(pizza, i + 1, c, n - 1, m - 1)) ans = (ans + f(pizza, i + 1, c, k - 1))%mod;
        }
        for(int i = c; i < m - 1; i++){
            if(check(pizza, r, c, n - 1, i) and check(pizza, r, i + 1, n - 1, m - 1)) ans = (ans + f(pizza, r, i + 1, k - 1))%mod;
        }
        return dp[r][c][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        memset(dp, -1, sizeof dp);
        return f(pizza, 0, 0, k - 1);
    }
};