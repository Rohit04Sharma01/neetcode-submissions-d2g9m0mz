class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;

        for (int num : st) {

            // start of sequence
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int len = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};