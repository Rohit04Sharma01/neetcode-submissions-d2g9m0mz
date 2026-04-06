class Solution {
public:
    int numRescueBoats(vector<int>& nums, int l) {
        int n = nums.size();
        int ans = 0;
        int start = 0;
        int end = n - 1;
        sort(nums.begin(), nums.end());
        while (start <= end) {
            int total = nums[start] + nums[end];
            if (total <= l) {
                start += 1;
                end -= 1;
            } else {
                end -= 1;
            }
            ans += 1;
        }
        return ans;
    }
};