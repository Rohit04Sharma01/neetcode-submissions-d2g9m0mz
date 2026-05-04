class Solution {
private:
    void utility(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int target, int idx, int n) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0 || idx == n) {
            return;
        }
        temp.push_back(nums[idx]);
        utility(nums, result, temp, target - nums[idx], idx, n);
        temp.pop_back();
        utility(nums, result, temp, target, idx + 1, n);
    }   
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = nums.size();
        utility(nums, result, temp, target, 0, n);
        return result;
    }
};