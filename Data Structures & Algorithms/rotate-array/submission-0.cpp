class Solution {
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k % n - 1);
        reverse(nums, k % n, n - 1);
    }
};