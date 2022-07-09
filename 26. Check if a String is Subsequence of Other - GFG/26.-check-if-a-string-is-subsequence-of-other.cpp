// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        //code here
        int ALen=A.length();
       int BLen=B.length();
       int Aidx=0;
       
       if(ALen>BLen){
           return false;
       }
       
       for(int i=0; i<BLen; i++){
           if(B[i]==A[Aidx]){
               Aidx++;
               if(Aidx==ALen){
                   return true;
               }
           }
       }
       
       return false;
    }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans == true)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends