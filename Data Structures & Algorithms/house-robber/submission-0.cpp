class Solution {
private: 
    int utility(vector<int>& nums, int idx, int n, vector<int>& dp) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int take = nums[idx] + utility(nums, idx + 2, n, dp);
        int nottake = utility(nums, idx + 1, n, dp);
        return dp[idx] = max(take, nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n + 2, 0);
        // return utility(nums, 0, n, dp);
        int next1 = 0;
        int next2 = 0;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            int take = nums[idx] + next2;
            int nottake = next1;
            int curr = max(take, nottake);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};