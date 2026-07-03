class DisjointUnionSet {
private:
    vector<int> rank;
public:
    vector<int> rep;
    DisjointUnionSet(int n) {
        rep.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            rep[i] = i;
        }
    }
    int find(int u) {
        if (u == rep[u]) {
            return u;
        }
        return rep[u] = find(rep[u]);
    }
    void Union(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if (rank[parentU] > rank[parentV]) {
            rep[parentV] = parentU;
            rank[parentU] += rank[parentV];
        } else {
            rep[parentU] = parentV;
            rank[parentV] += rank[parentU];
        }
        return;
    }
};

class Solution {
private:
    double dfs(int node, int target, vector<bool>& visited, vector<vector<pair<int, double>>>& graph) {
        if (node == target) {
            return 1;
        }
        visited[node] = true;
        for (auto& neigh: graph[node]) {
            int v = neigh.first;
            double w = neigh.second;
            if (!visited[v]) {
                double val = dfs(v, target, visited, graph);
                if (val != 0) {
                    return val * w;
                }
            }
        }
        return 0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> equationIdx;
        int nodeIdx = 0;
        for (auto& equation: equations) {
            for (int i = 0; i <= 1; i++) {
                if (equationIdx.find(equation[i]) == equationIdx.end()) {
                    equationIdx[equation[i]] = nodeIdx++;
                }
            }
        }
        vector<vector<pair<int, double>>> graph(nodeIdx);
        DisjointUnionSet dsu(nodeIdx);
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            int u = equationIdx[equations[i][0]];
            int v = equationIdx[equations[i][1]];
            dsu.Union(u, v);
            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, (double) 1.0 / values[i]});
        }
        vector<double> result;
        for (auto& query: queries) {
            string u = query[0];
            string v = query[1];
            if (equationIdx.find(u) == equationIdx.end() || equationIdx.find(v) == equationIdx.end() || dsu.find(equationIdx[u]) != dsu.find(equationIdx[v])) {
                result.push_back(-1);
            } else {
                vector<bool> visited(nodeIdx, 0);
                result.push_back(dfs(equationIdx[u], equationIdx[v], visited, graph));
            }
        }
        return result;
    }
};