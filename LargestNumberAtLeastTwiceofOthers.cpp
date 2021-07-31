#include <iostream>
#include <vector>
using namespace std;
int dominantIndex(vector<int> &nums){
    int max=nums[0],index=0, max2=0;
for (int i = 1; i < nums.size(); i++)
{
    if (nums[i]>max2){
        if (nums[i]>max){
            max2=max;
            max=nums[i];
            index=i;
        }
        else
        max2=nums[i];
    }
}
if (max2 * 2 <= max)
    return index;
else
    return -1;
}
int main(){
                 
   ios_base::sync_with_stdio(false);
cin.tie(NULL);               
              
     int t,x;
     cin >> t;   
     vector<int>v;
     while(t--){
            cin >> x;
            v.push_back(x);
     }

     cout << dominantIndex(v);
      return 0;
}