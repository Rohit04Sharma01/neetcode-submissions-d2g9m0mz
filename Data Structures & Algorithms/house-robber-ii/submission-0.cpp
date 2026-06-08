class Solution {
private:
    int utility(vector<int>& nums, int low, int high) {
        int n = nums.size();
        int next1 = 0;
        int next2 = 0;
        for (int idx = high; idx >= low; idx -= 1) {
            int take = nums[idx] + next2;
            int nottake = next1;
            int curr = max(take, nottake);
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(utility(nums, 0, n - 2), utility(nums, 1, n - 1));
    }
};