class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while (start <= end) {
            if (nums[start] == val) {
                swap(nums[start], nums[end--]);
            }
            else {
                start += 1;
            }
        }
        return end+1;
    }
};