class Solution {
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= nums[low] && nums[mid] > nums[high]) {
                low = mid + 1;
            } else if ((nums[mid] >= nums[low] && nums[mid] < nums[high]) || (nums[mid] < nums[low] && nums[mid] < nums[high])) {
                high = mid;
            }
        }
        return high;
    }
    int search(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high-low)/2;
            cout << mid << endl;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int idx = findMin(nums);
        if (idx == 0 || nums[0] > target) {
            return search(nums, idx, nums.size() - 1, target);
        }
        return search(nums, 0, idx - 1, target);
    }
};