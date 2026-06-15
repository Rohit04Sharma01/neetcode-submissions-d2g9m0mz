class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            for (int buy = 1; buy >= 0; buy -= 1) {
                int a = 0;
                int b = 0;
                if (buy) {
                    a = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                } else {
                    b = max(prices[idx] + dp[idx + 2][1], dp[idx + 1][0]);
                }
                dp[idx][buy] = max(a, b);
            }
        }
        return dp[0][1];
    }
};