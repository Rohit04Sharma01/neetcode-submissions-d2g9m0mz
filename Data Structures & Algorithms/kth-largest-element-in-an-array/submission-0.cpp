class Solution {
private:
    int quickSelect(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int idx = start;
        for (int i = start; i < end; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[idx++]);
            }
        }
        swap(nums[idx], nums[end]);
        return idx;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int p = quickSelect(nums, start, end);
            if (p == k) {
                return nums[p];
            } else if (p < k) {
                start = p + 1;
            } else {
                end = p - 1;
            }
        }
        return -1;
    }
};