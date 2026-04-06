class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token: tokens) {
            if (token == "+") {
                int f = st.top(); st.pop();
                int s = st.top(); st.pop();
                st.push(f + s);
            } else if (token == "-") {
                int f = st.top(); st.pop();
                int s = st.top(); st.pop();
                st.push(s - f);
            } else if (token == "*") {
                int f = st.top(); st.pop();
                int s = st.top(); st.pop();
                st.push(f * s);
            } else if (token == "/") {
                int f = st.top(); st.pop();
                int s = st.top(); st.pop();
                st.push(s / f);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};