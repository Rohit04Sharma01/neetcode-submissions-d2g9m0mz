class Solution {
public:
    int numSquares(int n) {
        int x = ceil(sqrt(n));
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        // return utility(n, x, dp);
        for (int j = 1; j <= n; j += 1) {
            int res = 1e7;
            for (int i = x; i >= 1; i -= 1) {
                unsigned int sq = i * i;
                if (sq <= j) {
                    res = min(res, 1 + dp[j - sq]);
                }
            }
            dp[j] = res;
        }
        return dp[n];
    }
};