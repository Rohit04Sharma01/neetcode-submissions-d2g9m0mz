class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_set<int> us;
        while (j < n) {
            if (us.find(s[j]) != us.end()) {
                while (true) {
                    us.erase(s[i]);
                    if (s[i++] == s[j]) {
                        break;
                    }
                }
            } else {
                us.insert(s[j]);
                ans = max(ans, j - i + 1);
                j += 1;
            }
        }
        return ans;
    }
};