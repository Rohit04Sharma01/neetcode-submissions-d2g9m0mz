class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ump;
        int n = s.size();
        vector<int> result;
        int start = -1;
        int mid = 0;
        for (int i = 0; i < n; i++) {
            ump[s[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            mid = max(mid, ump[s[i]]);
            if (mid == i) {
                result.push_back(i - start);
                start = i;
            }
        }
        return result;
    }
};