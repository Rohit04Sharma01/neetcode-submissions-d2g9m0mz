class Solution {
private:
    int utility(vector<vector<int>>& grid, int row, int col, int m, int n, vector<vector<int>>& dp) {
        if (row == n - 1 && col == m - 1) {
            return grid[row][col];
        }
        if (dp[row][col] != -1) return dp[row][col];
        int bottom = 1e7;
        int right = 1e7;
        if (row < n - 1) {
            bottom = utility(grid, row + 1, col, m, n, dp);
        }
        if (col < m - 1) {
            right = utility(grid, row, col + 1, m, n, dp);
        }
        return dp[row][col] = grid[row][col] + min(right, bottom);

    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // return utility(grid, 0, 0, m, n, dp);
        dp[n - 1][m - 1] = grid[n - 1][m - 1];
        for (int row = n - 1; row >= 0; row -= 1) { 
            for (int col = m - 1; col >= 0; col -= 1) {
                if (row == n - 1 && col == m - 1) {
                    continue;
                }
                int bottom = 1e7;
                int right = 1e7;
                if (row < n - 1) {
                    bottom = dp[row + 1][col];
                }
                if (col < m - 1) {
                    right = dp[row][col + 1];
                }
                dp[row][col] = grid[row][col] + min(right, bottom);
            }
        }
        return dp[0][0];
    }
};