class Solution {
private:
    void utility(vector<int>& nums, set<vector<int>>& result, vector<int>& temp, vector<bool>& idx, int n) {
        if (temp.size() == n) {
            result.insert(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            // if (i > 0 && nums[i] == nums[i - 1]) {
            //     continue;
            // }
            if (idx[i] == 0) {
                idx[i] = 1;
                temp.push_back(nums[i]);
                utility(nums, result, temp, idx, n);
                idx[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> idx(n, 0);
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        utility(nums, s, temp, idx, n);
        for (auto ele: s) {
            result.push_back(ele);
        }
        return result;
    }
};