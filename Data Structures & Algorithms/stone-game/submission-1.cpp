class Solution {
private:
    int utility(vector<int>& piles, int low, int high,
                vector<vector<int>>& dp) {

        if (low == high) {
            return piles[low];
        }

        if (dp[low][high] != -1) {
            return dp[low][high];
        }

        int takeLeft = piles[low] - utility(piles, low + 1, high, dp);
        int takeRight = piles[high] - utility(piles, low, high - 1, dp);

        return dp[low][high] = max(takeLeft, takeRight);
    }

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return utility(piles, 0, n - 1, dp) > 0;
        
    }
};