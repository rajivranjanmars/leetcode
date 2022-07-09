// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
        int totalPetrol = 0, totalDistance = 0;
       
       for(int i = 0; i < n; i++) {
           totalPetrol += p[i].petrol;
           totalDistance += p[i].distance;
       }
       
       if(totalDistance > totalPetrol) return -1;
       
       int candidate = 0, currPetrol = 0, currDist = 0;
       
       for(int i = 0; i < n; i++) {
           currPetrol += p[i].petrol;
           currDist += p[i].distance;
           
           if(currDist > currPetrol) {
               currDist = 0;
               currPetrol = 0;
               candidate = i + 1;
           }
       }
       
       return candidate;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends