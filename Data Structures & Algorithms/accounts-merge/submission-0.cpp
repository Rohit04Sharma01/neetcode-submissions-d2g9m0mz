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
        if (parentU == parentV) {
            return;
        }
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailIdx;
        unordered_map<int, string> idxName;
        unordered_map<int, string> idxEmail;
        
        int nodeIdx = 0;
        for (auto& account: accounts) {
            int m = account.size();
            for (int i = 1; i < m; i++) {
                if (emailIdx.find(account[i]) == emailIdx.end()) {
                    emailIdx[account[i]] = nodeIdx;
                    idxEmail[nodeIdx] = account[i];
                    idxName[nodeIdx] = account[0];
                    nodeIdx += 1;
                }
            }
        }
        DisjointUnionSet dsu(nodeIdx);
        for (auto& account: accounts) {
            int m = account.size();
            for (int i = 1; i < m - 1; i++) {
                dsu.Union(emailIdx[account[i]], emailIdx[account[i + 1]]);
            }
        }
        unordered_map<int, vector<string>> nameEmail;
        for (int i = 0; i < nodeIdx; i++) {
            nameEmail[dsu.find(i)].push_back(idxEmail[i]);
        }
        vector<vector<string>> result;
        for (auto& name: nameEmail) {
            vector<string> temp;
            temp.push_back(idxName[name.first]);
            sort(name.second.begin(), name.second.end());
            for (auto& email: name.second) {
                temp.push_back(email);
            }
            result.push_back(temp);
        }
        return result;
    }
};