class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX,ans,n=nums.size();;
        for(int i=0;i<n-2;i++)
        {
            int st=i+1;
            int end=n-1;
            while(st<end)
            {
                int k=nums[i]+nums[st]+nums[end];
                if(abs(k-target)<diff)
                {
                    diff=abs(k-target);
                    ans=k;
                }
                if(k>target)
                {
                    end--;
                }
                else if(k<target)
                {
                    st++;
                }
                else
                {
                    return k;
                }
            }
        }
        return ans;
    }
};