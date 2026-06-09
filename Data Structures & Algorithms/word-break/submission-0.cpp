class Solution {
private:
    bool utility(string& s, unordered_set<string>& us, int idx, int n, vector<int>& dp) {
        if (idx == n) {
            return true;
        }
        if (dp[idx] != -1) return dp[idx];
        for (int i = idx; i < n; i++) {
            string t = s.substr(idx, i - idx + 1);
            if (us.find(t) != us.end()) {
                bool res = utility(s, us, i + 1, n, dp);
                if (res) return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            for (int i = idx; i < n; i++) {
                string t = s.substr(idx, i - idx + 1);
                if (us.find(t) != us.end()) {
                    bool res = dp[i + 1];
                    if (res) {
                        dp[idx] = 1;
                        continue;
                    }
                }
            }
        }
        return dp[0];
        // return utility(s, us, 0, n, dp);
    }
};