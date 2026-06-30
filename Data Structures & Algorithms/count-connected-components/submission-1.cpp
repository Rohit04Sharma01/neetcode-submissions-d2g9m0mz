class DisjointUnionSet {
private:
    vector<int> rank;
public:
    vector<int> rep;
    DisjointUnionSet(int n) {
        rep.resize(n);
        rank.resize(n, 0);
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
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointUnionSet dsu(n);
        for (auto& edge: edges) {
            dsu.Union(edge[0], edge[1]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.rep[i] == i) {
                res += 1;
            }
        }
        return res;
    }
};
