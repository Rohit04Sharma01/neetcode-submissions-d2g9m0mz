class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ump;
        int n = order.size();
        for (int i = 0; i < n; i++) {
            ump[order[i]] = i;
        }
        int m = words.size() - 1;
        for (int i = 0; i < m ; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int m1 = w1.size();
            int m2 = w2.size();
            int j = 0;
            int k = 0;
            while (j < m1 && k < m2) {
                if (ump[w1[j]] == ump[w2[k]]) {
                    j += 1; k += 1;
                    continue;
                } else if (ump[w1[j]] > ump[w2[k]]) {
                    return false;
                } else {
                    break;
                }
            }
            if (k == m2 && j < m1) {
                return false;
            }
        }
        return true;
    }
};