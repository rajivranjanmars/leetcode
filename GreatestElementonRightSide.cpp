//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
#include <iostream>
#include <vector>
using namespace std;
vector<int> replaceElements(vector<int> arr) {
        int max=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for (int i = arr.size()-2; i >=0; i--)
        {int temp=max;
            if (max<arr[i])
            max=arr[i];
            arr[i]=temp;
        }
        return arr;
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
    vector<int> num=replaceElements( nums);
    
    for (int i=0; i <num.size(); i++){
        cout << num[i] << " ";
    }
    return 0;
}