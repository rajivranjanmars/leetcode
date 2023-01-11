
class Solution {
public:


int dfs(int src,vector<vector<int>> & vec,vector<bool> &visited,vector<bool>&ha){

    int ans1 = 0;

    visited[src] = true;

    if(ha[src] && src!=0){
        ans1+=2;
    }

    for(auto i:vec[src]){

        if(!visited[i]){
            ans1+=dfs(i,vec,visited,ha);
        }
    }

    if(!ha[src] && ans1>0 && src!=0){
        ans1+=2;
    }

    return ans1;

}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {

        vector<vector<int>> vec(n);

        vector<bool> visited(n,false);

        
        for(int i=0;i<edges.size();i++){

            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }


        return dfs(0,vec,visited,ha);

    }
};