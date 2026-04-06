class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int res = 1e7;
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            while (sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i += 1;
            }
            j += 1;
        }
        return res == 1e7 ? 0 : res;
    }
};