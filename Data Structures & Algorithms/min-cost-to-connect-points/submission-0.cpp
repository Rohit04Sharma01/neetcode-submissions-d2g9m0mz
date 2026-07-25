class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int node = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (node == -1 || minDist[j] < minDist[node])) {
                    node = j;
                }
            }
            visited[node] = true;
            ans += minDist[node];
            for (int j = 0; j < n; j++) {
                if (visited[j]) {
                    continue;
                }
                int dist = abs(points[node][0] - points[j][0]) + abs(points[node][1] - points[j][1]);
                minDist[j] = min(minDist[j], dist);
            }
        }
        return ans;
    }
};