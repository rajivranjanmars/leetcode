#include <iostream>
#include <vector>
using namespace std;
void duplicateZeros(vector<int> arr)
{
    int t = arr.size();
    for (int i = 0; i < t; i++){
        if (arr[i] == 0){
            for (int j = t - 1; j > i; j--){
                arr[j] = arr[j - 1];
            }
            i++;
        }
    }
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
    duplicateZeros(nums);
    return 0;
}