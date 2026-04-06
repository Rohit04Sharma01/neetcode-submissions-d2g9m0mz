class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        vector<int> count(n);
        string result;
        string size_of_word;
        for (int i = 0; i < n; i++) {
            result += strs[i];
            size_of_word += to_string(strs[i].size()) + '.';
        }
        reverse(begin(size_of_word), end(size_of_word));
        return result + size_of_word;
    }

    vector<string> decode(string s) {
        vector<string> result;
        while (!s.empty()) {
            int n = s.size();
            int i = n - 1;
            string size_of_word = "";
            while (s[i] != '.') {
                size_of_word += s[i];
                i--;
            }
            // reverse(begin(size_of_word), end(size_of_word));
            int n_size_of_word = stoi(size_of_word);
            result.push_back(s.substr(0, n_size_of_word));
            s = s.substr(n_size_of_word, n - n_size_of_word - size_of_word.size() - 1);
        }
        return result;
    }
};
