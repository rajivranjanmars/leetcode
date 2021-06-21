#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 void merge(vector<int> nums1, int m, vector<int> nums2, int n) {
       for(int i=0; i<n; i++){
            nums1[m + i] = nums2[i];
         }
        sort(nums1.begin(), nums1.end());
    }
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, x;
    cin >> t  ;
    vector<int> nums;
    for (int i = 0; i < t; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    int a;
     cin >> a ;
    vector<int> nums2;
    for (int i = 0; i < a; i++)
    {
        cin >> x;
        nums2.push_back(x);
    }
   
   merge(nums,  t, nums2,  a);
    return 0;
}
