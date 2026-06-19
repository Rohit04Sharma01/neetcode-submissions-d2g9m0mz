class Solution {
private:
    int utility(vector<int>& piles, int n, vector<int>& suffix, int idx, int M, vector<vector<int>>& dp) {
        if (idx >= n) {
            return 0;
        }
        if (2 * M >= n - idx) {
            return suffix[idx];
        }
        if (dp[idx][M] != -1) {
            return dp[idx][M];
        }
        int res = 0;
        for (int X = 1; X <= 2 * M; X++) {
            res = max(res, suffix[idx] - utility(piles, n, suffix, idx + X, max(M, X), dp));
        }
        return dp[idx][M] = res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n + 1, 0);
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i -= 1) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        // return utility(piles, n, suffix, 0, 1, dp);
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            for (int M = n; M >= 1; M -= 1) {
                if (2 * M >= n - idx) {
                    dp[idx][M] = suffix[idx];
                    continue;
                }
                int best = 0;

                for (int x = 1; x <= 2 * M; x++) {

                    best = max(
                        best,
                        suffix[idx] -
                        dp[idx + x][max(M, x)]
                    );
                }

                dp[idx][M] = best;
            }
        }
        return dp[0][1];
    }
};