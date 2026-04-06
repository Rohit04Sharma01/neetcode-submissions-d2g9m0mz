class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mat[mid][m-1] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return binary_search(mat[high].begin(), mat[high].end(), target);
    }
};