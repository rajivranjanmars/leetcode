// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
      void pw(int a[], int j, string str[], vector<string> &v)
    {

        if (j == -1)
        {
            v.push_back("");
            return;
        }
        pw(a + 1, j - 1, str, v);
        int n2 = v.size(), n1 = str[a[0]].size();
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                v.push_back(str[a[0]][i] + v[j]);
            }
        }
        v.erase(v.begin(), v.begin() + n2);
    }
    vector<string> possibleWords(int a[], int N)
    {
        string str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> v;
        pw(a, N - 1, str, v);
        return v;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends