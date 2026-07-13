class Solution {
public:
    string gcdOfStrings(string s, string t) {
        if (s + t != t + s)
            return "";

        return s.substr(0, gcd(s.size(), t.size()));
    }
};