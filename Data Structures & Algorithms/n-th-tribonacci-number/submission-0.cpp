class Solution {
private:
    int utility(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = utility(n-1, dp) + utility(n-2, dp) + utility(n-3, dp);
    }
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        if (n == 2) return 1;
        // vector<int> dp(n+1, -1);
        // dp[0] = 0;
        // dp[1] = dp[2] = 1;
        int first = 0; 
        int second = 1;
        int third = 1;
        for (int idx = 3; idx <= n; idx += 1) {
            int curr = first + second + third;
            first = second;
            second = third;
            third = curr;
        }
        // return utility(n, dp);
        return third;
    }
};