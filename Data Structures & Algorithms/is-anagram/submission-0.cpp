class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) return false;
        unordered_map<char, int> ump;
        for (int i = 0; i < n; i++) {
            ump[s[i]] += 1;
        }
        for (int i = 0; i < n; i++) {
            ump[t[i]] -= 1;
        }
        for (int i = 0; i < n; i++) {
            if(ump[s[i]] != 0) return false;
        }
        return true;
    }
};
