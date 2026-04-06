class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            int target = -1 * nums[i];
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j],nums[k]};
                    res.push_back(temp);
                    while (j < k && nums[j] == temp[1]) {
                        j += 1;
                    }
                    while (k > j && nums[k] == temp[2]) {
                        k -= 1;
                    }
                } else if (sum < target) {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }
        return res;
    }
};