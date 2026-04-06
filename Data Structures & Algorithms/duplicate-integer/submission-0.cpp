class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> us;
        for (int i = 0; i < n; i++) {
            if (us.find(nums[i]) != us.end()) return true;
            us.insert(nums[i]);
        }
        return false;
    }
};