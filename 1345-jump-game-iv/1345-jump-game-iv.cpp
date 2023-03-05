class Solution {
public:
     int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> umap;

        for (int i=0;i<n;i++) {
            umap[arr[i]].push_back(i);
        }

        queue<int> q;

        q.push(0);

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        while(!q.empty()) {

            int front = q.front();
            q.pop();
            if (front == n-1)
                return dist[n-1];
            
            if ((front+1 < n) && dist[front+1]==INT_MAX) {
                dist[front+1] = dist[front]+1;
                q.push(front+1);
            }
            if ((front-1 >= 0) && dist[front-1]==INT_MAX) {
                dist[front-1] = dist[front]+1;
                q.push(front-1);
            }

            for (auto it: umap[arr[front]]) {
                if (it!=front && dist[it]==INT_MAX) {
                    dist[it] = dist[front]+1;
                    q.push(it);
                }
            }

            // clear map since in next check we do not again want to iterate over the above for loop for same arr[front] value.
            umap.erase(arr[front]);

        }

        return -1;


        
    }
};