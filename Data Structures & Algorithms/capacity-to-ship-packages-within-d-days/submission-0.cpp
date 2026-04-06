class Solution {
    bool ship(vector<int>& weights, int days, int cap) {
        int n = weights.size();
        int temp = cap;
        for (int i = 0; i < n; i++) {
            if (temp - weights[i] < 0) {
                days -= 1;
                temp = cap;
            } 
            if (days <= 0 || weights[i] > cap) return false;
            temp -= weights[i];
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1;
        int h = accumulate(weights.begin(), weights.end(), 0);
        while (l < h) {
            int m = l + (h - l) / 2;
            if (ship(weights, days, m)) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return h;
    }
};