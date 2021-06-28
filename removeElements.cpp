//https://leetcode.com/problems/remove-element/
#include <iostream>
#include <vector>   
using namespace std;
 int removeElement(vector<int>& nums, int val) {
     if (nums.size()>1){
     int j=nums.size()-1;
     bool a=false;
     for (int i = 0; i < j;){
        while(nums[i]!=val&& i<j)
            i++;
            while(nums[j]==val&& i<j)
            j--;
            if (nums[j]!=val && nums[i]!=nums[j]){
            swap(nums[j],nums[i]);
            a=true;
            }
   }     
   if(!a)
   return nums.size();
   else
    return j;  
     }
     else if (nums.size()==1){
         if (nums[0]==val)
         return 0;
         else
         return 1;
     }
     else
      return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x;
    cin >> t;
    vector<int> nums;
    while (t--)
    {
        cin >> x;
        nums.push_back(x);
    }
    cin >> x;
    cout << removeElement(nums,x);
    return 0;
}