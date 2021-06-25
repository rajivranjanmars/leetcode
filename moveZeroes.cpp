//https://leetcode.com/problems/move-zeroes/   //
#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int> nums){
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[j] != 0){
                    nums[i] = nums[j];
                    nums[j] = 0;
                    break;
                }
            }
        }
    }    

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
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