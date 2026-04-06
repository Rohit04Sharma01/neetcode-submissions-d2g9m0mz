class Solution {
public:
    string simplifyPath(string path) {
        vector<string> arr;
        int i = 0;
        int n = path.size();
        while (i < n) {
            while (i < n && path[i] == '/') {
                i += 1;
            }
            string dir = "";
            while (i < n && path[i] != '/') {
                dir += path[i];
                i += 1;
            }
            if (!dir.empty()) arr.push_back(dir);
        }
        string ans = "";
        vector<string> st;
        for (const string& s: arr) {
            if (s == "..") {
                if (!st.empty())
                    st.pop_back();
            } else if (s != ".") {
                st.push_back(s);
            }
        }
        for (const string& s: st) {
            ans = ans + "/" + s;
        }
        if (ans.size() == 0) return "/";
        return ans;
    }
};