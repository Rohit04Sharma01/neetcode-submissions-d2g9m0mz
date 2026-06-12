class Solution {
private:
    int utility(vector<vector<int>>& mat, int m, int n, int row, int col, vector<vector<int>>& dp) {
        if (row == m || col == n) {
            return 0;
        } 
        if (mat[row][col]) return 0;
        if (row == m - 1 && col == n - 1) {
            return 1;
        } 
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = utility(mat, m, n, row + 1, col, dp) + utility(mat, m, n, row, col + 1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if (mat[m - 1][n - 1]) return 0;
        vector<vector<unsigned int>> dp(m + 1, vector<unsigned int> (n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for (int row = m - 1; row >= 0; row -= 1) {
            for (int col = n - 1; col >= 0; col -= 1) {
                if (row == m - 1 && col == n - 1 || mat[row][col]) {
                    continue;
                }
                dp[row][col] = dp[row + 1][col] + dp[row][col + 1]; 
            }
        }
        return dp[0][0];
    }
};