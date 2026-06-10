class Solution {
private:
    int utility(vector<int>& nums, int target, int n, vector<int>& dp) {
        if (target == 0) {
            return 1;
        }
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (int i = 0; i < n; i += 1) {
            if (nums[i] <= target) {
                res += utility(nums, target - nums[i], n, dp);
            }
        }
        return dp[target] = res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // return utility(nums, target, n, dp);
        for (int i = 1; i <= target; i++) {
            long res = 0;
            for (int j = 0; j < n; j += 1) {
                if (nums[j] <= i) {
                    res += dp[i - nums[j]];
                }
            }
            dp[i] = res;
        }
        return dp[target];
    }
};