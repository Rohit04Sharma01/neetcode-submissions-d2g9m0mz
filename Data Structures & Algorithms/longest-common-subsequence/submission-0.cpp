class Solution {
private:
    int utility(string& s, string& t, int i, int j, int n, int m, vector<vector<int>>& dp) {
        if (i == n || j == m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int one = 0;
        int two = 0;
        if (s[i] == t[j]) {
            one = 1 + utility(s, t, i + 1, j + 1, n, m, dp);
        } else {
            two = max(utility(s, t, i + 1, j, n, m, dp), utility(s, t, i, j + 1, n, m, dp));
        }
        return dp[i][j] = max(one, two);
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // return utility(s, t, 0, 0, n, m, dp);
        for (int i = n - 1; i >= 0; i -= 1) {
            for (int j = m - 1; j >= 0; j -= 1) {
                int one = 0;
                int two = 0;
                if (s[i] == t[j]) {
                    one = 1 + dp[i + 1][j + 1]; 
                } else {
                    two = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = max(one, two);
            }
        }
        return dp[0][0];
    }
};