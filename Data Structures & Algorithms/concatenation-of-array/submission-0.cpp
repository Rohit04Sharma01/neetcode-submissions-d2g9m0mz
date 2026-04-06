class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int m = 2*n;
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = nums[i%n];
        }
        return res;
    }
};