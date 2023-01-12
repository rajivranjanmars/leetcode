class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->n = n;
        this->labels = labels;
        adj.resize(n);
        for(auto &u: edges){
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }
        vector<int> ans(n);
        vector<int> freq(26, 0);
        solve(0, -1, freq, ans);
        return ans;
    }
    void solve(int pos, int last, vector<int> &freq, vector<int> &ans){
        int idx = labels[pos] - 'a';
        freq[idx]++;
        int prev = freq[idx];
        int total = 1;
        for(auto &u: adj[pos]){
            if(u != last){
                solve(u, pos, freq, ans);
                total += freq[idx] - prev;
                prev = freq[idx];
            }
        }
        ans[pos] = total;
    }
private:
    int n;
    string labels;
    vector<vector<int>> adj;
};