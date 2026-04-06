class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (i != j-1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = n - 1;
                long long two = nums[i] + nums[j];
                while (k < l) {
                    long long sum = two + nums[k] + nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(temp);
                        while (k < l && nums[k] == temp[2]) {
                            k += 1;
                        }
                        while (l > k && nums[l] == temp[3]) {
                            l -= 1;
                        }
                    }
                    else if (sum < target) {
                        k += 1;
                    } else {
                        l -= 1;
                    }
                }
            }
        }
        return res;
    }
};