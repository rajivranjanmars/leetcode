#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
  vector<int> sortedSquares(vector<int>nums) {
       for (int i = 0; i <nums.size(); i++) {
           nums[i] *=nums[i];
       }
       sort(nums.begin(), nums.end());
       return nums;
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
   vector<int> a =  sortedSquares( nums);
   for (int i = 0; i < a.size();i++) {
       cout << a[i] << " ";
   }
    return 0;
}