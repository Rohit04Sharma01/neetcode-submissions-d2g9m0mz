class Solution {
private:
    int utility(vector<int>& nums, int target, int idx, int n,
                unordered_map<string, int>& ump) {

        if (idx == n) {
            return target == 0;
        }

        string key = to_string(idx) + "," + to_string(target);

        if (ump.find(key) != ump.end()) {
            return ump[key];
        }

        int pos = utility(nums, target - nums[idx], idx + 1, n, ump);
        int neg = utility(nums, target + nums[idx], idx + 1, n, ump);

        return ump[key] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> ump;
        int n = nums.size();

        // Maximum possible absolute sum
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Base case:
        // At idx = n, only target = 0 has 1 way
        ump[to_string(n) + ",0"] = 1;

        // Fill DP bottom-up
        for (int idx = n - 1; idx >= 0; idx--) {

            for (int t = -sum; t <= sum; t++) {

                string key = to_string(idx) + "," + to_string(t);

                int pos =
                    ump[to_string(idx + 1) + "," +
                        to_string(t - nums[idx])];

                int neg =
                    ump[to_string(idx + 1) + "," +
                        to_string(t + nums[idx])];

                ump[key] = pos + neg;
            }
        }

        return ump[to_string(0) + "," + to_string(target)];
    }
};