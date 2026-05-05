class Solution {
private:
    void utility(string& digits, int idx, string answer, int n, vector<string>& result, unordered_map<char, string>& ump) {
        if (idx == n) {
            result.push_back(answer);
            return;
        }
        string temp = ump[digits[idx]];
        int t_length = temp.size();
        for (int i = 0; i < t_length; i++) {
            utility(digits, idx + 1, answer + temp[i], n, result, ump);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        unordered_map<char, string> ump = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        utility(digits, 0, "", n, result, ump);
        return result;
    }
};