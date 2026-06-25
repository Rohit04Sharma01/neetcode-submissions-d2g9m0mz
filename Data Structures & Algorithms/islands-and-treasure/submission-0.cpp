class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    pq.push({0, i, j});
                }
            }
        }
        int dir[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            int dist = node[0];
            int row = node[1];
            int col = node[2];

            for (int i = 0; i <= 3; i++) {
                int nrow = row + dir[i];
                int ncol = col + dir[i + 1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != -1 && grid[nrow][ncol] > dist + 1) {
                    pq.push({dist + 1, nrow, ncol});
                    grid[nrow][ncol] = dist + 1;
                }
            }
        }
        return;
    }
};
