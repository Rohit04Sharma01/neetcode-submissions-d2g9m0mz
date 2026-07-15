class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        int n = nums.size();
        int carry = 1;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            if (nums[idx] == 9) {
                nums[idx] = 0;
            } else {
                nums[idx] += 1;
                carry = 0;
                break;
            }
        }
        if (carry) {
            nums.emplace(nums.begin(), 1);
        }
        return nums;
    }
};