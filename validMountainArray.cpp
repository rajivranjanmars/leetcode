#include <iostream>
#include <vector>
using namespace std;
bool validMountainArray(vector<int> arr)
{
    
    if (arr.size() < 3)
        return false;

    bool high = true;
    bool mountain = true;
     if (arr[0]>arr[1])
    mountain = false;

    for (int i = 1; i < arr.size()-1; i++)
    {
      
        if (high)
        {
            if (arr[i] >= arr[i + 1])
                high = false;
                if (arr[i] == arr[i + 1]){
                mountain = false;
                break;
                }
        }
        else
        {
            if (arr[i] <= arr[i+1])
                mountain = false;
                if (arr[i] == arr[i + 1]){
                mountain = false;
                break;
                }
        }
       
    }
    if (arr[arr.size()-1]>arr[arr.size()-2])
    mountain = false;
    
    return mountain;
}
 int main()
{
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

    cout << validMountainArray(nums);
    return 0;
}