class Solution {
private:
    void utility(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& idx, int n) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!idx[i]) {
                idx[i] = 1;
                temp.push_back(nums[i]);
                utility(nums, result, temp, idx, n);
                idx[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> idx(n, 0);
        utility(nums, result, temp, idx, n);
        return result;
    }
};