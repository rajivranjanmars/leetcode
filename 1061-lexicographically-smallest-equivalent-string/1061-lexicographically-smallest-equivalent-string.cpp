class Solution {
public:
     char DFSFindMinchar(unordered_map<char,vector<char>>&adj,char curr_ch,vector<int>&visited) 
     {
         visited[curr_ch - 'a']=1;
         char minChar=curr_ch;
         for(char &v:adj[curr_ch])
         {
             if(visited[v - 'a']==0)
             {
                 minChar= min(minChar ,DFSFindMinchar(adj,v,visited));
             }
         }
         return minChar;
     }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        int m=baseStr.length();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++)
        {
            char u =s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        string result;
        for(int i=0;i<m;i++)
        {
            char ch=baseStr[i];
            vector<int>visited(26,0);
            char minChar= DFSFindMinchar(adj,ch,visited);
            result.push_back(minChar);
        }
        return result ;
    }
};