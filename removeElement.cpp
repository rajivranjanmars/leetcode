#include <iostream>
#include <vector>
using namespace std;
  int removeElement(vector<int>nums, int val) {
      int t=nums.size();
      cout << t;
        for (int i = nums.size()-1; i >=0; i--){
            if (nums[i] == val){
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
    cin >> x;
      cout << removeElement(nums,x) ;
    return 0;
}