class Solution {
private:
    int utility(vector<int>& cost, int idx, int n, vector<int>& dp) {
        if (idx >= n) return 0;
        int one = utility(cost, idx + 1, n, dp);
        int two = utility(cost, idx + 2, n, dp);
        return dp[idx] = cost[idx] + min(one, two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+2, 0);
        // utility(cost, 0, n, dp);
        int next1 = 0;
        int next2 = 0;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            int one = next1;
            int two = next2;
            int curr = cost[idx] + min(one, two);
            next2 = one;
            next1 = curr;
        }
        return min(next1, next2);
    }
};