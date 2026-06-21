class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];
            int s2 = result.back()[0];
            int e2 = result.back()[1];
            if (s2 <= e1 && s1 <= e2) {
                result.pop_back();
                result.push_back({min(s1, s2), max(e1, e2)});
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};