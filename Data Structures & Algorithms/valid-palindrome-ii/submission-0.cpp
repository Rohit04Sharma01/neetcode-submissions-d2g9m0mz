class Solution {
private:
    bool Palindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return Palindrome(s, start+1, end) | Palindrome(s, start,end-1);
            }
            start += 1; end -= 1;
        }
        return true;
    }
};