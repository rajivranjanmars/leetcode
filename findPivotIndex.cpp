#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>nums){
    int n=nums.size();
cout<< endl;
vector <int> s(n+2,0);
s[0]=0;
s[1]=nums[0];
for (int i = 2; i <= n; i++){
    s[i]=s[i-1]+nums[i-1];
}
for (int i = 1; i <= n; i++)
{
    if (s[i-1]==s[n] -s[i] )
    return i-1;  
}
return -1;
}

    int main(){

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
    cout << endl;
    cout << pivotIndex(nums);
    return 0;
}
