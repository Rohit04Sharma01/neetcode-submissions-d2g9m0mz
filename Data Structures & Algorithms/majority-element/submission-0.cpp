class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = nums[0];
        int vote = 0;
        for (int i = 0; i < n; i++) {
            if (cand == nums[i]) {
                vote += 1;
            } else if (vote > 0) {
                vote -= 1;
            } else {
                cand = nums[i];
                vote = 1;
            }
        }
        return cand;
    }
};