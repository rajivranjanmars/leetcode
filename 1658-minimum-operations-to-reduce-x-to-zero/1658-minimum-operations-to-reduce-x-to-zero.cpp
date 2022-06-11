class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int sum = 0;
        for(auto v : nums) {
            sum += v;
        }
        int rest = sum - x;
        int cs = 0;
        int ans = INT_MAX;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if (j <= i) {
                j = i;
                cs = 0;
            }
            for(; j < n && cs < rest; j++) {
                cs = cs + nums[j];
            }
            if (cs == rest) {
                ans = min(ans, n - (j-i));
            }
            cs -= nums[i];
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};