class Solution {
    bool utility(string& s1, string& s2, string& s3, int i, int j,
                 vector<vector<int>>& dp) {

        if (i == s1.size() && j == s2.size()) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int k = i + j;

        bool ans = false;

        if (i < s1.size() && s1[i] == s3[k]) {
            ans = ans || utility(s1, s2, s3, i + 1, j, dp);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            ans = ans || utility(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = ans;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size();
        int m = s2.size();

        if (n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1;
        for (int i = n; i >= 0; i -= 1) {
            for (int j = m; j >= 0; j -= 1) {
                if (i == n && j == m) continue;
                int k = i + j;

                bool ans = false;

                if (i < s1.size() && s1[i] == s3[k]) {
                    ans = ans || dp[i + 1][j];
                }

                if (j < s2.size() && s2[j] == s3[k]) {
                    ans = ans || dp[i][j + 1];
                }

                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};