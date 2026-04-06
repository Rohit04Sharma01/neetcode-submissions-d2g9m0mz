class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int ans = 0;
        while (start < end) {
            ans = max(ans, (end - start) * min(nums[start], nums[end]));
            if (nums[start] <= nums[end]) {
                start += 1;
            } else {
                end -= 1;
            }
        }
        return ans;
    }
};