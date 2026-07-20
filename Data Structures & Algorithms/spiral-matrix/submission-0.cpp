class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int left = 0;
        int top = 0;
        int right = mat[0].size() - 1;
        int bottom = mat.size() - 1;
        int row, col;
        vector<int> res;
        while (left <= right && top <= bottom) {
            for (col = left; col <= right; col += 1) {
                res.push_back(mat[top][col]);
            }
            top += 1;
            for (row = top; row <= bottom; row += 1) {
                res.push_back(mat[row][right]);
            }
            right -= 1;
            if (top <= bottom) {
                for (col = right; col >= left; col -= 1) {
                    res.push_back(mat[bottom][col]);
                }
                bottom -= 1;
            }
            if (left <= right) {
                for (row = bottom; row >= top; row -= 1) {
                    res.push_back(mat[row][left]);
                }
                left += 1;
            }
        }
        return res;
    }
};