#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<int> plusOne(vector<int> digits)
{
    int s=digits.size();
    if (digits[s-1]!=9)
    {
       digits[s-1]++; 
       return digits;
    }
    else if(digits[0]!=9){
        digits[s-1]=0;
        digits[s-2]++;
        int i=s-1;
        while (digits[i]>9)
        {
          int b;  
        }
        
        
    }
    
    
    
}

int main(){
                 
   ios_base::sync_with_stdio(false);
cin.tie(NULL);               
              
        int t, x;
        cin >> t ;
        vector <int> v;
        while(t--){
            cin >> x ;
            v.push_back(x);
        } 
        vector <int> nums=plusOne(v);     
         for(int i=0; i<nums.size(); i++) {
             cout << nums[i] << " ";
         }    
 return 0;
}