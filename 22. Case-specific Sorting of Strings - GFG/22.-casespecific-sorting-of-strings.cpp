// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here


string x=str;
       sort(x.begin(),x.end());
       string:: iterator it1=x.begin();
       string:: iterator it2=x.begin();
       for(int i=0;i<n;i++){
           if(x[i]>96){
               break;
           }
           it2++;
       }
       
       for(auto it=str.begin();it!=str.end();it++){
           char temp=*it;
           if(temp>96){
               *it=*it2;
               it2++;
           }else{
               *it=*it1;
               it1++;
           }
       }
       return str;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends