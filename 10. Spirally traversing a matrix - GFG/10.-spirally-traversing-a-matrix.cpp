// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
  void outer(vector<vector<int>>& mat,int r, int c, int b, vector<int>& ans){
     for(int i{b};i<c-b;i++) ans.push_back(mat[b][i]);
     for(int i{b+1};i<r-b;i++) ans.push_back(mat[i][c-b-1]);
      
     if(r-b-1==b) return; 
     for(int i{c-b-2}; i>=b;i--) ans.push_back(mat[r-b-1][i]);
      
     if(b==c-b-1) return;
     for(int i{r-b-2}; i>b;i--) ans.push_back(mat[i][b]);
   }
    


 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int b=0,limit=min(r,c);
        if(limit & 1) limit++;

        while(b<limit/2) outer(matrix,r,c,b++,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends