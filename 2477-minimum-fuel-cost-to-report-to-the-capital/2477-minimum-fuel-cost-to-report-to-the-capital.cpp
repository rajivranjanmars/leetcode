class Solution {
#define ll long long
	vector<ll> adj[100001];
	ll ans;
	ll dfs(int node, int par, int seat, int dist) {
		ll res = 1;
		for (auto &e : adj[node]) {
			if (e != par) {
				res += dfs(e, node, seat, dist + 1);
			}
		}
		if (node == 0) return ans;
		ans += (res / seat) * dist + (res % seat ? 1 : 0);
		return res % seat;
	}
public:
	long long minimumFuelCost(vector<vector<int>>& r, int s) {
		for (auto &e : r) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		return dfs(0, -1, s, 0);
	}
};