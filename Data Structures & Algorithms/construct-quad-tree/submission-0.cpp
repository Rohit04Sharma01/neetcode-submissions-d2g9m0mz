class Solution {
private:
    Node* utility(vector<vector<int>>& grid,
                  int n,
                  int row,
                  int col) {

        int sum = 0;

        // calculate sum in current square
        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++) {
                sum += grid[i][j];
            }
        }

        Node* t = new Node();

        // all 0
        if (sum == 0) {
            t->val = false;
            t->isLeaf = true;
            return t;
        }

        // all 1
        if (sum == n * n) {
            t->val = true;
            t->isLeaf = true;
            return t;
        }

        // mixed values → split
        t->isLeaf = false;
        t->val = true;

        int half = n / 2;

        t->topLeft =
            utility(grid,
                    half,
                    row,
                    col);

        t->topRight =
            utility(grid,
                    half,
                    row,
                    col + half);

        t->bottomLeft =
            utility(grid,
                    half,
                    row + half,
                    col);

        t->bottomRight =
            utility(grid,
                    half,
                    row + half,
                    col + half);

        return t;
    }

public:
    Node* construct(vector<vector<int>>& grid) {

        return utility(grid,
                       grid.size(),
                       0,
                       0);
    }
};