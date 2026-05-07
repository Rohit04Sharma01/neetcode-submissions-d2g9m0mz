class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col, int n, int m, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row == n || col == m || visited[row][col] || board[row][col] == 'X') {
            return;
        }
        visited[row][col] = 1;
        int dir[] = {-1, 0, 1, 0, -1};
        for (int i = 0; i <= 3; i++) {
            int nr = row + dir[i];
            int nc = col + dir[i + 1];
            dfs(board, nr, nc, n, m, visited);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0, n, m, visited);
            dfs(board, i, m - 1, n, m, visited);
        }
        for (int i = 0; i < m; i++) {
            dfs(board, 0, i, n, m, visited);
            dfs(board, n - 1, i, n, m, visited);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};