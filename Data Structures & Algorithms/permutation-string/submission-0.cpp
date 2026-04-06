class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int i = 0;
        int j = 0;
        unordered_map<char, int> ump;
        for (int i = 0; i < n1; i++) {
            ump[s1[i]] += 1;
        }

        while (j < n2) {
            if (ump.find(s2[j]) != ump.end()) {
                if (ump[s2[j]] > 0) {
                    ump[s2[j]] -= 1;
                    if (j - i + 1 == n1) {
                        return true;
                    }
                } else {
                    while (s2[i] != s2[j]) {
                        if (ump.find(s2[i]) != ump.end()) {
                            ump[s2[i]] += 1;
                        }
                        i += 1;
                    }
                    i += 1;
                }
            } else {
                while (i < j) {
                    if (ump.find(s2[i]) != ump.end()) {
                        ump[s2[i]] += 1;
                    }
                    i += 1;
                }
                i += 1;
            }
            j += 1;
        }
        return false;
    }
};