class Solution {
private:
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for (int row = m - 1; row >= 0; row -= 1) {
            for (int col = n - 1; col >= 0; col -= 1) {
                if (row == m - 1 && col == n - 1) {
                    continue;
                }
                dp[row][col] = dp[row + 1][col] + dp[row][col + 1]; 
            }
        }
        return dp[0][0];
    }
};