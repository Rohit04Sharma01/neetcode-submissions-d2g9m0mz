class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total&1) return false;
        int sum = total / 2;
        vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);

        next[0] = true;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            for (int j = 1; j <= sum; j++) {
                bool take = false;

                if (nums[idx] <= j) {
                    take =
                        next[j - nums[idx]];
                }

                bool notTake =
                    next[j];

                curr[j] =
                    take || notTake;
            }
            next = curr;
        }
        return curr[sum];
    }
};