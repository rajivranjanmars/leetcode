//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> nums){
    int t=nums.size();
   for(int i=t-1; i>0;i--){
       if(nums[i] ==nums[i-1])
       nums.erase(nums.begin()+i);
   }
   return nums.size();
}
int main(){
   ios_base::sync_with_stdio(false);
cin.tie(NULL);               
     int t , x;
    vector<int> nums;
    cin >>t;
    while (t--){
        cin >> x;
      nums.push_back(x)  ;
    }
   
 cout  << removeDuplicates(nums)    ;  
 return 0;
}   