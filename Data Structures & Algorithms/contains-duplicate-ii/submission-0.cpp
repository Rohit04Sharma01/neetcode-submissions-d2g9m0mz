class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int, int> ump;
        while (j < n) {
            if (j - i > k) {
                ump[nums[i++]] -= 1;
            }
            if (ump.find(nums[j]) != ump.end() && ump[nums[j]] > 0) {
                return true;
            }
            ump[nums[j]] += 1;
            j += 1;
        }
        return false;
    }
};