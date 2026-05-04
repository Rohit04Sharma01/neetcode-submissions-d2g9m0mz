class Solution {
private:
    void utility(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int target, int idx, int n) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            if (nums[i] > target) break;

            temp.push_back(nums[i]);
            utility(nums, result, temp, target - nums[i], i + 1, n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // set<vector<int>> s;
        vector<int> temp;
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        utility(nums, result, temp, target, 0, n);
        // for (auto ele: s) {
        //     result.push_back(ele);
        // }
        return result;
    }
};