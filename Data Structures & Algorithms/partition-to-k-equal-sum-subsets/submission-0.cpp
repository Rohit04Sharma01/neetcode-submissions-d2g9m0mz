class Solution {
private:
    bool solve(vector<int>& nums, vector<int>& sides, int idx, int target, int n, int m) {
        if (idx == n) {
            for (int j = 0; j < m; j++) {
                if (sides[j] != target) {
                    return false;
                }
            }
            return true;
        }
        for (int i = 0; i < m; i++) {
            if (sides[i] + nums[idx] > target) {
                continue;
            }
            if (i > 0 && sides[i] == sides[i - 1]) {
                continue;
            }
            sides[i] += nums[idx];
            if (solve(nums, sides, idx + 1, target, n, m)) {
                return true;
            }
            sides[i] -= nums[idx];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k) {
            return false;
        }
        int target = total / k;
        vector<int> sides(k, 0);
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        return solve(nums, sides, 0, target, n, k);
    }
};