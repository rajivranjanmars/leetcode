//https://leetcode.com/problems/sort-array-by-parity/
#include <iostream>
#include <vector>   
using namespace std;
void moveZeroes(vector<int> nums){
    for (int i = 0,j=nums.size()-1; i < j   ;){
        while(nums[i]%2==0&& i<j)
            i++;
            while(nums[j]%2==1&& i<j)
            j--;
             swap(nums[j],nums[i]);
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
    moveZeroes(nums);
    return 0;
}
/*
4 7 6 9 4 2 8 3 4 5 6
4 6 6 9 4 2 8 3 4 5 7
4 6 6 4 4 2 8 3 9 5 7
*/