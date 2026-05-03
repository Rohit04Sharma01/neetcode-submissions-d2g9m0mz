class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            jump = max(jump, nums[i] + i);
            if (jump == i) {
                return false;
            }
        }
        return true;
    }
};