class Solution {
public:
    vector<vector<int>> result;
    vector<int> dir = {-1, 0, 1, 0, -1};

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& vis,
             int r, int c) {

        int n = heights.size();
        int m = heights[0].size();

        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];

            if (nr >= 0 && nc >= 0 &&
                nr < n && nc < m &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(heights, vis, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        // Pacific
        for (int i = 0; i < n; i++)
            dfs(heights, pac, i, 0);

        for (int j = 0; j < m; j++)
            dfs(heights, pac, 0, j);

        // Atlantic
        for (int i = 0; i < n; i++)
            dfs(heights, atl, i, m - 1);

        for (int j = 0; j < m; j++)
            dfs(heights, atl, n - 1, j);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};