// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
         map<int,int> count;
       for(int i=0;i<n;i++)
           count[arr[i]]++;
       auto compare=[&count](pair<int,int> a,pair<int,int> b)->bool{
           if(a.second!=b.second)
               return a.second>b.second;
           return a.first<b.first;
       };
       vector<pair<int,int>> sort_order;
       for(pair<int,int> key :count)
           sort_order.push_back(key);
       std::sort(sort_order.begin(),sort_order.end(),compare);
       vector<int>v;
       for(int i=0;i<sort_order.size();i++){
           for(int j=0;j<sort_order[i].second;j++)
               v.push_back(sort_order[i].first);
       }
       return v; 
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends