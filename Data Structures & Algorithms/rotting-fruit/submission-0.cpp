class Solution {
private:
    int utility(vector<vector<int>>& grid, int n, int m) {
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int dir[] = {-1, 0, 1, 0, -1};
        int res = 0;
        while (!q.empty()) {
            int k = q.size();
            for (int i = 0; i < k; i++) {
                auto f = q.front(); q.pop();
                int x = f.first.first;
                int y = f.first.second;
                res = f.second;
                for (int j = 0; j <= 3; j++) {
                    int nr = x + dir[j];
                    int nc = y + dir[j + 1];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({{nr, nc}, f.second + 1});
                    }
                }
            }
        }
        return res;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = utility(grid, n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
            cout << endl;
        }
        return res;
    }
};