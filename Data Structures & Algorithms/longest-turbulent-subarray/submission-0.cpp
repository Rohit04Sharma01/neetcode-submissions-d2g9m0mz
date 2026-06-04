class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int i = 0;
        int j = 0;
        int flag = 0;
        int res = 0;
        int n = arr.size();
        while (j < n - 1) {
            if (flag == 0) {
                if (arr[j] > arr[j + 1]) {
                    flag = 1; j += 1;
                } else if (arr[j] < arr[j + 1]) {
                    flag = -1; j += 1;
                } else {
                    flag = 0; i = ++j;
                }
            } else if (flag == 1) {
                if (arr[j] < arr[j + 1]) {
                    j += 1; flag = -1;
                } else {
                    flag = 0; i = j;
                } 
            } else {
                if (arr[j] > arr[j + 1]) {
                    j += 1; flag = 1;
                } else {
                    flag = 0; i = j;
                } 
            }
            res = max(res, j - i);
        }
        return res + 1;
    }
};