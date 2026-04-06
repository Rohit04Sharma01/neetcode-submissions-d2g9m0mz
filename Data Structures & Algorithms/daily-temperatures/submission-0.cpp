class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> res(n, 0);
        st.push({temp.back(), n - 1});
        for (int i = n - 2; i >= 0; i -= 1) {
            while (!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top().second - i;
            }
            st.push({temp[i], i});
        }
        return res;
    }
};