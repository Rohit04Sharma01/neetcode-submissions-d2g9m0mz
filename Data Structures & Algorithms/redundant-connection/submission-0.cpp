class Solution {
    int dfs(int node, vector<bool>& visited, unordered_set<int>& cycle, int parent, vector<vector<int>>& graph) {
        visited[node] = 1;
        for (auto& neigh: graph[node]) {
            if (visited[neigh] == 1 && neigh != parent) {
                cycle.insert(neigh);
                cycle.insert(node);
                return 1;
            } else if (visited[neigh] == 0) {
                int val = dfs(neigh, visited, cycle, node, graph);
                if (val) {
                    if (cycle.find(node) != cycle.end()) {
                        return 0;
                    } else {
                        cycle.insert(node);
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> cycle;
        vector<bool> visited(n + 1, false);
        dfs(1, visited, cycle, -1, graph);
        for (int i = n - 1; i >= 0; i -= 1) {
            auto& edge = edges[i];
            if (cycle.find(edge[0]) != cycle.end() && cycle.find(edge[1]) != cycle.end()) {
                return edge;
            }
        }
        return {};
    }
};