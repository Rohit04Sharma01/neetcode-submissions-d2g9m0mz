class Solution {
    bool palindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
    bool alphanumeric(char ch) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int j = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (alphanumeric(s[i])) {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[j++] = tolower(s[i]); 
                } else {
                    s[j++] = s[i];
                }
            }
        }
        return palindrome(s, 0, j-1);
    }
};