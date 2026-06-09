class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // vector<vector<int>> dp(
        //     n + 1,
        //     vector<int>(n + 1, 0)
        // );
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int idx = n - 1;
             idx >= 0;
             idx--) {

            for (int prevIdx = idx - 1;
                 prevIdx >= -1;
                 prevIdx--) {

                int take = 0;

                if (prevIdx == -1 ||
                    nums[idx] > nums[prevIdx]) {

                    take = 1 +
                        next[idx + 1];
                }

                int nottake =
                    next[prevIdx + 1];

                curr[prevIdx + 1] =
                    max(take, nottake);
            }
            next = curr;
        }

        return curr[0];
    }
};