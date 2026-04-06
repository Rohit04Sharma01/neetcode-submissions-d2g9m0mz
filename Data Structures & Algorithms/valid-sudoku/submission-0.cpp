class Solution {
public:
    bool validate(vector<vector<char>>& board, int i, int j, int n, int m) {
        char ch = board[i][j];
        for (int l = 0; l < n; l++) {
            if (l != i && board[l][j] == ch) {
                return false;
            }
        }
        for (int l = 0; l < m; l++) {
            if (l != j && board[i][l] == ch) {
                return false;
            }
        }
        for (int l = i/3*3; l < i/3*3+3; l++) {
            for (int m = j/3*3; m < j/3*3+3; m++) {
                if (i != l && j != m && board[l][m] == ch) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.' && !validate(board, i, j, n, m)) {
                    return false;
                }
            }
        }
        return true;
    }
};