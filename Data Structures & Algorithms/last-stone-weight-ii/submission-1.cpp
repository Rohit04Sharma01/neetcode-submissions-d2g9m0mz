class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int totalSum = 0;

        for (int x : stones) {
            totalSum += x;
        }

        vector<bool> dp(totalSum + 1, false);

        dp[0] = true;

        for (int stone : stones) {

            for (int s = totalSum; s >= stone; s--) {

                dp[s] = dp[s] || dp[s - stone];
            }
        }

        int best = 0;

        for (int s = totalSum / 2; s >= 0; s--) {

            if (dp[s]) {
                best = s;
                break;
            }
        }

        return totalSum - 2 * best;
    }
};