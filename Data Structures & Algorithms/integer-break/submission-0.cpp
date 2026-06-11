class Solution {
private:
    int utility(int n, vector<int>& dp) {

        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int res = 0;

        for (int j = 1; j < n; j++) {

            res = max(res, max(j * (n - j), j * utility(n - j, dp)));
        }

        return dp[n] = res;
    }

public:
    int integerBreak(int n) {

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            int res = 0;

            for (int j = 1; j < i; j++) {

                res = max(res, max(j * (i - j), j * utility(i - j, dp)));
            }

            dp[i] = res;
        }
        return dp[n];
        // return utility(n, dp);
    }
};