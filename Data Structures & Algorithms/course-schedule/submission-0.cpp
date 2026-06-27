class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pq) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        int n = pq.size();
        for (int i = 0; i < n; i++) {
            graph[pq[i][1]].push_back(pq[i][0]);
            indegree[pq[i][0]] += 1;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i += 1) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        if (q.empty()) {
            return false;
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto& neigh: graph[node]) {
                if (--indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        for (int i = 0; i < numCourses; i += 1) {
            if (indegree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};