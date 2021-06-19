#include <iostream>
#include <vector>
using namespace std;
 int findMaxConsecutiveOnes(vector<int>nums) {
       int  count=0,max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(max<count)
                max=count;
                count=0;
            }
            else
                count++;

               // cout << i << " " <<count<< " " << max << endl;
        }
         if(max<count)
                max=count;
        return max;
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
      cout << findMaxConsecutiveOnes(nums);
    return 0;
}