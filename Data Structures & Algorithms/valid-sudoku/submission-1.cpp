class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int> (9, 0));
        vector<vector<int>> col(9, vector<int> (9, 0));
        vector<vector<int>> sub(9, vector<int> (9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (row[i][num] || col[j][num] || sub[i/3*3+j/3][num]){
                        return false;
                    }
                    row[i][num] = col[j][num] = sub[i/3*3+j/3][num] = 1;
                }
            }
        }
        return true;
    }
};