#include <iostream>
#include <vector>
using namespace std;
 int findNumbers(vector<int>nums) {
       int count=0;
       for (int i = 0; i < nums.size(); i++){
           int even=0;
          while ((nums[i]/10)){
             even++;
             nums[i]/=10;
             //cout  << nums[i] << " " << even << endl;
         }
         if (even%2==1)
         count++;  
        // cout <<count << " "  <<i << " " << even << endl;  
       }
       return count;
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
      cout << findNumbers(nums);
    return 0;
}