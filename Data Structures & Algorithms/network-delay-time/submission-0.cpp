class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<vector<int>>> adjList(n + 1);
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto n = pq.top();
            pq.pop();
            int u = n[1];
            int w = n[0];
            for (auto& neigh: adjList[u]) {
                int v = neigh[0];
                int nw = neigh[1];
                if (nw + w < dist[v]) {
                    dist[v] = nw + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            } else {
                res = max(res, dist[i]);
            }
        }
        return res;
    }
};