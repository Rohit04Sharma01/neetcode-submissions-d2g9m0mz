class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int res = 0;
        for (char ch = 'A'; ch <= 'Z'; ch += 1) {
            int i = 0;
            int j = 0;
            int alive = k;
            while (j < n) {
                if (s[j] != ch) {
                    if (alive > 0) {
                        alive -= 1;
                    } else {
                        while (s[i] == ch) {
                            i += 1;
                        }
                        i += 1;
                    }
                }
                res = max(res, j - i + 1);
                j += 1;
            }
        }
        return res;
    }
};