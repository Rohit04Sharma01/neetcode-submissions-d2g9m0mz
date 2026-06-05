class Solution {
public:
    bool canReach(string s,
                  int minJump,
                  int maxJump) {

        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            int addIndex = i - minJump;

            if (addIndex >= 0 &&
                dp[addIndex]) {
                reachable++;
            }

            int removeIndex =
                i - maxJump - 1;

            if (removeIndex >= 0 &&
                dp[removeIndex]) {
                reachable--;
            }

            if (reachable > 0 &&
                s[i] == '0') {

                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};