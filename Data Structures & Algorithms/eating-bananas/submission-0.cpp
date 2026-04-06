class Solution {
private:
    int eat(vector<int>& piles, int h, int rate) {
        int ans = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            ans += ceil((double) piles[i] / rate);
            if (ans > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (eat(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};