class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        int i = 0;
        unordered_map<char, int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        while (i < n) {
            if (s[i] == 'I' && (i + 1 < n && s[i + 1] == 'V' || s[i + 1] == 'X')) {
                res += s[i + 1] == 'V' ? 4 : 9;
                i += 2;  
            } else if (s[i] == 'X' && (i + 1 < n && s[i + 1] == 'L' || s[i + 1] == 'C')) {
                res += s[i + 1] == 'L' ? 40 : 90;
                i += 2;
            } else if (s[i] == 'C' && (i + 1 < n && s[i + 1] == 'D' || s[i + 1] == 'M')) {
                res += s[i + 1] == 'D' ? 400 : 900;
                i += 2;
            } else {
                res += ump[s[i]];
                i += 1;
            }
        }
        return res;
    }
};