class Solution {
private:
    bool isPalindrome(string& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void utility(string& s, vector<vector<string>>& result, vector<string>& path, int start, int n) {
        if (start == n) {
            result.push_back(path);
            return;
        }
        int length = n - start;
        for (int i = 1; i <= length; i++) {
            string temp = s.substr(start, i);
            if (isPalindrome(temp)) {
                path.push_back(temp);
                utility(s, result, path, start + i, n);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        int n = s.size();
        utility(s, result, path, 0, n);
        return result;
    }
};