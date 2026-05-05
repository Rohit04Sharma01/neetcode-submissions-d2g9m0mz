class Solution {
private:
    bool utility(vector<vector<char>>& board, string word, int idx, int n, int m, int word_length, int row, int col) {
        if (word_length == idx) {
            return true;
        }
        if (row < 0 || col < 0 || row == n || col == m) {
            return false;
        }
        if (board[row][col] != word[idx]) {
            return false;
        }
        char ch = board[row][col];
        board[row][col] = ' ';
        if (utility(board, word, idx + 1, n, m, word_length, row + 1, col) || utility(board, word, idx +1, n, m, word_length, row, col + 1) || utility(board, word, idx + 1, n, m, word_length, row - 1, col) || utility(board, word, idx + 1, n, m, word_length, row, col - 1)) {
            return true;
        }
        board[row][col] = ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int word_length = word.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && utility(board, word, 0, n, m, word_length, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};