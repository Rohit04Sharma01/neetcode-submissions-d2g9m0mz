class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(), coins.end());
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount + 1, 0));
        vector<int> prev(amount + 1, 0);
        // int val = utility(coins, amount, n - 1, dp);
        for (int a = 0; a <= amount; a++) {
            prev[a] = (a % coins[0]) ? 1e7 : a / coins[0];
        }
        for (int idx = 1; idx < n; idx++) {
            vector<int> curr(amount + 1, 0);
            for (int a = 0; a <= amount; a++) {
                int take = 1e7;
                if (a >= coins[idx]) {
                    take = 1 + curr[a - coins[idx]];
                }
                int nottake = prev[a];
                curr[a] = min(take, nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return ans >= 1e7 ? -1 : ans;
    }
};