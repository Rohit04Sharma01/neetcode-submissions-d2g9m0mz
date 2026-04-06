class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high) {
            int total = arr[low] + arr[high];
            if (total == t) {
                return {low + 1, high + 1};
            } else if (total < t) {
                low++;
            } else {
                high--;
            }
        }
        return {-1, -1};
    }
};