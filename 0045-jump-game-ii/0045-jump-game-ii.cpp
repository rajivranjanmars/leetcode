class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int curReach = 0;
        int jumps = 0;
        
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i]+i>curMax){
                curMax = nums[i]+i;
            }
            if(curReach == i){
                jumps++;
                curReach = curMax;
            }
        }
        return jumps;
    }
};