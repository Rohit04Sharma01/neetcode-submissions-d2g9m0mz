class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col, int n, int m) {
        visited[row][col] = 1;
        int dir[] = {-1, 0, 1, 0, -1};
        int res = 0;
        for (int i = 0; i <= 3; i++) {
            int nr = row + dir[i];
            int nc = col + dir[i + 1];
            if (nr < 0 || nc < 0 || nr == n || nc == m || !grid[nr][nc]) {
                res += 1;
            } else if (!visited[nr][nc]) {
                res += dfs(grid, visited, nr, nc, n, m);
            }
        }
        return res;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    return dfs(grid, visited, i, j, n, m);
                }
            }
        }
        return 0;
    }
};