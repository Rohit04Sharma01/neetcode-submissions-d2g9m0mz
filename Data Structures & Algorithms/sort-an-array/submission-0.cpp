class Solution {
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> arr(high-low+1);
        int i = low;
        int j = mid+1;
        int k = 0;
        while (i <= mid || j <= high) {
            if (i == mid+1) {
                arr[k++] = nums[j++];
            } else if (j == high + 1) {
                arr[k++] = nums[i++];
            } else if (nums[i] <= nums[j]) {
                arr[k++] = nums[i++];
            } else {
                arr[k++] = nums[j++];
            }
        }
        for (int l = 0; l < k; l++) {
            nums[low + l] = arr[l];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};