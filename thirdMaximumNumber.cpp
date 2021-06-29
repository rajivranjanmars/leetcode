//https://leetcode.com/problems/third-maximum-number/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int thirdMax(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int t=nums.size();
    for (int i = 1; i <nums.size() ; i++){
        if(nums[i]==nums[i-1]){
        nums.erase(nums.begin() + i);
        i--;
        }
        
    }
    if (nums.size()==1)
    return nums[0];
    else if (nums.size()==2)
    return nums[1];
    else{
        return nums[nums.size()-3];
    }
   
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
    cout << thirdMax(nums);
    return 0;
}