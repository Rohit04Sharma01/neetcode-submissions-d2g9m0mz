class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            swap(mat[i++], mat[j--]);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < m; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
};