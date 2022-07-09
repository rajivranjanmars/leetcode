// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
         vector<int> ans(n,0);
       
       ans[0] = 1;
       
       for(int i=1;i<n;i++){
           int idx = i-1,cnt = 1;
           if(price[i] < price[idx]){
               ans[i] = cnt;
           }
           
           else{
               while(price[i] >= price[idx] && idx>=0){
                   cnt+=ans[idx];
                   idx-=ans[idx];
               }
               ans[i] = cnt;
           }
       }
       
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends