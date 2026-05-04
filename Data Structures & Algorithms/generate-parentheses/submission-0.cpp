class Solution {
private:
    void utility(int left, int right, string& str, vector<string>& result, int n) {
        if (right > left) {
            return;
        }
        if (left == n && left == right) {
            result.push_back(str);
            return;
        }
        if (left < n) {
            str += '(';
            utility(left + 1, right, str, result, n);
            str.pop_back();
        }
        if (right < n) {
            str += ')';
            utility(left, right + 1, str, result, n);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        utility(0, 0, str, result, n);
        return result;
    }
};