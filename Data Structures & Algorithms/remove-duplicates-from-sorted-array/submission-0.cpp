class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int it = 0;
        for (int i = 1; i < n; i++) {
            if (nums[it] != nums[i]) {
                nums[++it] = nums[i];
            }
        }
        return it + 1;
    }
};