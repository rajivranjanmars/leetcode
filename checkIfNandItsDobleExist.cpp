#include <iostream>
#include <vector>
using namespace std;
  bool checkIfExist(vector<int>arr) {
      bool check=false;
      for (int i = 0; i < arr.size(); i++){
          if (check)
          break;
          for (int j = 0; j <arr.size(); j++){
              if(i!=j){
              if (arr[i]==2*arr[j]){
              check=true;
              break;
              }
              }
          }
      }
    return check;
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
   
      cout << checkIfExist(nums) ;
    return 0;
}