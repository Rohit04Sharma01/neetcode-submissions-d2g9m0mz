class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> curr(amount + 1, 0);
        vector<int> next(amount + 1, 0);
        curr[0] = next[0] = 1;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            for (int a = 1; a <= amount; a += 1) {
                long long take = 0;
                if (coins[idx] <= a) {
                    take = curr[a - coins[idx]];
                }
                long long nottake = next[a];
                curr[a] = take + nottake;
            }
            next = curr;
        }
        return curr[amount];     
    }
};