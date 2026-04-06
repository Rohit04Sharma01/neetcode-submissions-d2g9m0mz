class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int i = 0; 
        int m = min(strs[0].size(), strs.back().size());
        string ans = "";
        while (i < m) {
            if (strs[0][i] != strs.back()[i]) {
                return ans;
            }
            ans += strs[0][i];
            i++;
        }
        return ans;
    }
};