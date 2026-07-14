class Solution {
private:
    int sumOfNum(int n) {
        int res = 0;
        while (n) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while (n != 1) {
            n = sumOfNum(n);
            if (us.find(n) != us.end()) {
                return false;
            }
            us.insert(n);
        }
        return true;
    }
};