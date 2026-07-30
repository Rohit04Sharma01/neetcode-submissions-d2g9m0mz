class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        int rev = 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = sign * x;
        }
        while (x > 0) {
            int y = x % 10;
            if (rev > (INT_MAX / 10)) {
                return 0;
            }
            rev = rev * 10 + y;
            x /= 10;
        }
        return rev * sign;
    }
};