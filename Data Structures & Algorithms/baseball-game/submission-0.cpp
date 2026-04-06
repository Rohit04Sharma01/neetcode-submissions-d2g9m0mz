class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int> st;
        for (const string& str: op) {
            if (str == "C") {
                st.pop();
            } else if (str == "D") {
                st.push(st.top() * 2);
            } else if (str == "+") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first + second);
            } else {
                st.push(stoi(str));
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};