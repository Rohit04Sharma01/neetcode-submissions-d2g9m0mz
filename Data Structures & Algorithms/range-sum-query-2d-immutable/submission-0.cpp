class NumMatrix {
    vector<vector<int>> arr;
public:
    NumMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        arr = vector<vector<int>> (n, vector<int> (m));
        arr[0][0] = nums[0][0];
        for (int i = 1; i < n; i++) arr[i][0] = nums[i][0] + arr[i-1][0];
        for (int i = 1; i < m; i++) arr[0][i] = nums[0][i] + arr[0][i-1];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                arr[i][j] = nums[i][j] + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = col1 == 0 ? 0 : arr[row2][col1-1];
        int up = row1 == 0 ? 0 : arr[row1-1][col2];
        int diag = row1 == 0 || col1 == 0 ? 0 : arr[row1-1][col1-1];
        int main = arr[row2][col2];
        return main - left - up + diag;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */