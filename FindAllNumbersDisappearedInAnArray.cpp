//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> nums){
    sort(nums.begin(), nums.end());
    int t = nums.size();
    for (int i = 1; i < nums.size(); i++){
        if (nums[i] == nums[i - 1]){
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    int a = 0;
    vector<int> v;
    for (int i = 1; i <= t; i++){
        if (nums[a] == i)
            a++;
        else
            v.push_back(i);
    }
    return v;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x;
    cin >> t;
    vector<int> nums;
    while (t--){
        cin >> x;
        nums.push_back(x);
    }
    vector<int> a = findDisappearedNumbers(nums);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}