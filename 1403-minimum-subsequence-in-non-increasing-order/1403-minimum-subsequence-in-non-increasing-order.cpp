class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int k=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(sum>k){
                k+=nums[i];
                sum-=nums[i];
                if(sum>k)
                nums.pop_back();
            } 
        }
        return nums;
    }
};