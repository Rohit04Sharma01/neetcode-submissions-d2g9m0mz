class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row == n || col == m || visited[row][col] || !grid[row][col]) {
            return 0;
        }
        visited[row][col] = 1;
        int dir[] = {-1, 0, 1, 0, -1};
        int res = 1;
        for (int i = 0; i <= 3; i++) {
            int nr = row + dir[i];
            int nc = col + dir[i + 1];
            res += dfs(grid, visited, nr, nc, n, m);
        }
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    res = max(res, dfs(grid, visited, i, j, n, m));
                }
            }
        }
        return res;
    }
};