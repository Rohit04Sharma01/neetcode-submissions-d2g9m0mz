class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        for (auto& edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int m = q.size();
            remainingNodes -= m;
            for (int i = 0; i < m; i++) {
                int node = q.front(); q.pop();
                for (auto& neigh: adjList[node]) {
                    degree[neigh] -= 1;
                    if (degree[neigh] == 1) {
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};