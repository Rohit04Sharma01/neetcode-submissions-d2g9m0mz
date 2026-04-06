class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ump;
        for (string& str: strs) {
            string key = str;
            sort(str.begin(), str.end());
            ump[str].push_back(key); 
        }
        vector<vector<string>> res;
        for (auto const& [key, value]: ump) {
            res.push_back(value);
        }
        return res; 
    }
};
