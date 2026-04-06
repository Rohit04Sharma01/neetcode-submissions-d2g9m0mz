class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int stock = nums[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            stock = min(stock, nums[i]);
            if ((i == n-1 || nums[i] > nums[i+1]) && nums[i] - stock > 0) {
                ans += nums[i] - stock;
                stock = 1e7;
            }
        }
        return ans;
    }
};