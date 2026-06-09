class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dpMax(n);
        vector<int> dpMin(n);

        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        int ans = nums[0];

        for (int i = 1; i < n; i++) {

            dpMax[i] = max({
                nums[i],
                nums[i] * dpMax[i - 1],
                nums[i] * dpMin[i - 1]
            });

            dpMin[i] = min({
                nums[i],
                nums[i] * dpMax[i - 1],
                nums[i] * dpMin[i - 1]
            });

            ans = max(ans, dpMax[i]);
        }

        return ans;
    }
};