class Solution {
public:
    vector<bool> checkIfPrerequisite(int n,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {

        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto &edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<bool>> pre(n, vector<bool>(n, false));

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neigh : graph[node]) {

                pre[neigh][node] = true;

                for (int i = 0; i < n; i++) {
                    if (pre[node][i])
                        pre[neigh][i] = true;
                }

                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(pre[q[1]][q[0]]);
        }

        return ans;
    }
};