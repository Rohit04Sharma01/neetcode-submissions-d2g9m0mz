class Solution {
private: 
    void utility(int n, int start, int k, vector<vector<int>>& result, vector<int>& temp) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        int end = n - (k - temp.size()) + 1;
        for (int i = start; i <= end; i++) {
            temp.push_back(i);
            utility(n, i + 1, k, result, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        utility(n, 1, k, result, temp);
        return result;
    }
};