#include <iostream>
#include <vector>
using namespace std;
  int removeDuplicates(vector<int>nums) {
        for (int i =nums.size()-1; i >0; i--){
            if (nums[i] ==nums[i-1]){
               nums.erase(nums.begin() + i);
            }
         }
      return nums.size();
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
      cout << removeDuplicates(nums);
    return 0;
}