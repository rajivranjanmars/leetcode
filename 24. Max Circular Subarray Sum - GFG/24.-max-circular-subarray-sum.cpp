// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
   int kadanes(int arr[],int n)

    {

        int ans=INT_MIN; int sum=0; 

        for(int i=0;i<n;i++)

        {

            sum+=arr[i]; 

            if(sum>ans)

            ans=sum; 

            if(sum<0) sum=0;

        }

        return ans;

    }

    int circularSubarraySum(int arr[], int num){

        int x=kadanes(arr,num); int sum=0; 

        for(int i=0;i<num;i++)

       {  sum+=arr[i]; arr[i]=-1*arr[i];}

        int y=kadanes(arr,num); 

        int z=sum+y; 

        if(z==0) return x; 

        return max(z,x); 

        

    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends