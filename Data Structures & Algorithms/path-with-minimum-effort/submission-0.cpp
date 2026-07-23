class Solution {
private:
    vector<int> dir = {-1, 0, 1, 0, -1};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0}); // {effort, row, col}

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (row == n - 1 && col == m - 1)
                return effort;

            if (effort > dist[row][col])
                continue;

            for (int i = 0; i < 4; i++) {
                int nrow = row + dir[i];
                int ncol = col + dir[i + 1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {

                    int edgeCost = abs(heights[row][col] - heights[nrow][ncol]);
                    int newEffort = max(effort, edgeCost);

                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, nrow, ncol});
                    }
                }
            }
        }

        return 0;
    }
};