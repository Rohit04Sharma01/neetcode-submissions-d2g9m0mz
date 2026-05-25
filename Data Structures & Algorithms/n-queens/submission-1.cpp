class Solution {
private:
    bool check(vector<string>& board, int n, int row, int col) {
        for (int i = row; i >= 0; i--) if (board[i][col] == 'Q') return false; 
        for (int i = col; i >= 0; i--) if (board[row][i] == 'Q') return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 'Q') return false;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(vector<vector<string>>& result, vector<string>& board, int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(board, n, row, i)) {
                board[row][i] = 'Q';
                solve(result, board, row + 1, n);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(result, board, 0, n);
        return result;
    }
};