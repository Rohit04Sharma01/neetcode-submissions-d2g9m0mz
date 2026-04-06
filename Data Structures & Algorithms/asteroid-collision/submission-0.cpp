class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (const int& x: asteroids) {
            if (st.empty() || (st.top() > 0 && x > 0) || (st.top() < 0 && x < 0 || x > 0)) {
                st.push(x);
            } else if (st.top() > 0 && x < 0) {
                int last = st.top();
                while (!st.empty() && st.top() > 0 && st.top() <= abs(x)) {
                    last = st.top();
                    if (st.top() == abs(x)) {
                        st.pop();
                        break;
                    }
                    st.pop();
                } 
                if (last != abs(x) && (st.empty() || st.top() < 0)) {
                    st.push(x);
                }    
            } 
        }
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};