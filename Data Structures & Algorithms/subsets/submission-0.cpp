class Solution {
private:
    void utility(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int idx, int n) {
        result.push_back(temp);
        for (int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            utility(nums, result, temp, i + 1, n);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = nums.size();
        utility(nums, result, temp, 0, n);
        return result;
    }
};