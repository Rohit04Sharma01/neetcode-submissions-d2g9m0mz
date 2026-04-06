class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int find = target - nums[i];
            if (ump.find(find) != ump.end()) {
                return {ump[find], i};
            }
            ump[nums[i]] = i;
        }
        return {-1, -1};
    }
};
