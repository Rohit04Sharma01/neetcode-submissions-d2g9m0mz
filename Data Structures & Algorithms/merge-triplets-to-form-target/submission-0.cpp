class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> present(3, false);
        int res = 0;
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int i = 0; i < 3; i++) {
                if (triplets[j][i] > target[i]) {
                    flag = false;
                }
            }
            if (flag) {
                if (triplets[j][0] == target[0]) {
                    present[0] = true;
                }
                if (triplets[j][1] == target[1]) {
                    present[1] = true;
                }
                if (triplets[j][2] == target[2]) {
                    present[2] = true;
                }
            }
        }
        if (present[0] != true || present[1] != true || present[2] != true) {
            return false;
        }
        return true;
    }
};