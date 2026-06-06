class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        unordered_map<int, int> ump;
        for (auto el: hand) {
            ump[el] += 1;
        }
        sort(hand.begin(), hand.end());
        for (auto el: hand) {
            if (ump[el] > 0) {
                int target = el;
                for (int i = 1; i <= groupSize; i += 1) {
                    if (ump.find(target) != ump.end() && ump[target] > 0) {
                        ump[target] -= 1;
                        target += 1;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};