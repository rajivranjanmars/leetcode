class Solution {
public:
    int arraySign(vector<int>& nums) {
        int a=1;
       for(int i=0;i<nums.size();i++) {
            if(nums[i]<0)
             a*=-1;
        if(nums[i]==0)
            return 0;
         if(nums[i]>0)
             a*=1;
       }
        if(a<0)
            return -1;
        return 1;
    }
};