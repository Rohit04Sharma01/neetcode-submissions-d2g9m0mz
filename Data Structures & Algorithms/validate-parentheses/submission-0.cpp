class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (const char& ch: s) {
            if (st.empty()) {
                if (ch == ')' || ch == ']' || ch =='}') {
                    return false;
                } else {
                    st.push(ch);
                }
            } else if (ch == ')') {
                if (st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (ch == ']') {
                if (st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (ch == '}') {
                if (st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(ch);
            }
        }
        return st.empty() ? true : false;
    }
};