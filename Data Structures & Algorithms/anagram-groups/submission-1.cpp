class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for (string& str: strs) {
            vector<int> idx(26, 0);
            string key;
            // sort(str.begin(), str.end());
            for (char& ch: str) {
                idx[ch - 'a'] += 1;
            }
            for (int i = 0; i < 26; i++) {
                if (idx[i]) {
                    for (int j = 0; j < idx[i]; j++) {
                        key += ('a'+i);
                    }
                }
            }
            ump[key].push_back(str); 
        }
        vector<vector<string>> res;
        for (auto const& [key, value]: ump) {
            res.push_back(value);
        }
        return res;
    }
};
