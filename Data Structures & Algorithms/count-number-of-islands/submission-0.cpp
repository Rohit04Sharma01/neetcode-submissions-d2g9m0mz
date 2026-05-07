class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col, int n, int m) {
        if (row < 0 || col < 0 || row == n || col == m || visited[row][col] || grid[row][col] == '0') {
            return;
        }
        visited[row][col] = 1;
        int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i <= 3; i++) {
            int nr = row + dir[i];
            int nc = col + dir[i + 1];
            dfs(grid, visited, nr, nc, n, m);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    res += 1;
                }
            }
        }
        return res;
    }
};