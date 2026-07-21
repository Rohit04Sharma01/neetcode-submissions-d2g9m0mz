class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        double res = pow(x, n / 2);
        res *= res;
        return n % 2 == 0 ? res : res * (n < 0 ? (double) 1 / x : x);
    }
};