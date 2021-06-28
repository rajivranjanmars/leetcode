//https://leetcode.com/problems/height-checker/
#include <iostream>
#include <algorithm>
#include <vector>   
using namespace std;
 int heightChecker(vector<int> heights) {
        vector<int> expected;
        expected=heights;
        sort(expected.begin(), expected.end());
        int unexpected=0;
        for (int i = 0; i < heights.size(); i++){
           if (heights[i]!=expected[i])
           unexpected++;
        }
        return unexpected;
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
    cin >> x;
    cout << heightChecker(nums);
    return 0;
}