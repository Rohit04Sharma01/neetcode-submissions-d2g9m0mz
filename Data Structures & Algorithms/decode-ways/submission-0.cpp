class Solution {
private:
    int utility(string& s, int idx, int n, vector<int>& dp) {
        if (idx == n) return 1;
        if (dp[idx] != -1) return dp[idx];
        if (s[idx] == '0') return 0;
        int one = 0;
        int two = 0;
        if (s[idx] == '1') {
            one = utility(s, idx + 1, n, dp);
            if (idx < n - 1) {
                two = utility(s, idx + 2, n, dp);
            }
        } else if (s[idx] == '2') {
            one = utility(s, idx + 1, n, dp);
            if (idx < n - 1 && s[idx  + 1] <= '6') {
                two = utility(s, idx + 2, n, dp);
            }
        } else {
            one = utility(s, idx + 1, n, dp);
        }
        return dp[idx] = one + two;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        // vector<int> dp(n + 1, 0);
        // return utility(s, 0, n, dp);
        // dp[n] = 1;
        int curr = 0;
        int next1 = 1;
        int next2 = 0;
        for (int idx = n - 1; idx >= 0; idx -= 1) {
            int one = 0;
            int two = 0;
            if (s[idx] == '0') curr = 0;
            else if (s[idx] == '1') {
                one = next1;
                if (idx < n - 1) {
                    two = next2;
                }
            } else if (s[idx] == '2') {
                one = next1;
                if (idx < n - 1 && s[idx  + 1] <= '6') {
                    two = next2;
                }
            } else {
                one = next1;
            }
            curr = one + two;
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }
};