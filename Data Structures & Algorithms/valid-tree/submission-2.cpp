class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (auto& neigh: graph[node]) {
            if (visited[neigh] == 0) {
                dfs(neigh, graph, visited);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, graph, visited);
                count += 1;
            }
        }
        if (count > 1) {
            return false;
        }
        visited = vector<bool> (n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            int node = n.first;
            int parent = n.second;
            for (auto& neigh: graph[node]) {
                if (visited[neigh] && parent != neigh) {
                    return false;
                } else if (!visited[neigh]){
                    q.push({neigh, node});
                    visited[neigh] = true;
                }
            }
        }
        return true;
    }
};
