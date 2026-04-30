class Solution {
private:
    int quickSelect(vector<vector<int>>& points, int start, int end) {
        int pivot = points[end][0] * points[end][0] +
                    points[end][1] * points[end][1];

        int idx = start;

        for (int i = start; i < end; i++) {
            int dist = points[i][0] * points[i][0] +
                       points[i][1] * points[i][1];

            if (dist <= pivot) {
                swap(points[i], points[idx]);
                idx++;
            }
        }

        swap(points[idx], points[end]);
        return idx;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int start = 0, end = points.size() - 1;

        while (start <= end) {
            int p = quickSelect(points, start, end);

            if (p == k) break;
            else if (p < k) start = p + 1;
            else end = p - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};