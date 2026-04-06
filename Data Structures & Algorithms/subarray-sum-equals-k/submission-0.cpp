class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int sum = 0;
        int res = 0;
        ump[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            // if (sum == k) {
            //     res += 1;
            //     int x = sum - k;
                // if (ump.find(x) != ump.end()) {
                //     res += ump[x];
                // }
            // } else {
            int x = sum - k;
            if (ump.find(x) != ump.end()) {
                res += ump[x];
            }
            // }
            ump[sum] += 1;
        }
        return res;
    }
};