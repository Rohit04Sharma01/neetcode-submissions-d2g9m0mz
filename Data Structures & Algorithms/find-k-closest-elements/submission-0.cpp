class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int diff = INT_MAX;
        // int idx = -1;
        // for (int i = 0; i < n; i++) {
        //     int val = abs(arr[i] - x);
        //     if (diff > val) {
        //         diff = val;
        //         idx = i; 
        //     }
        // }
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            if (idx > 0 && (idx == arr.size() || abs(arr[idx - 1] - x) <= abs(arr[idx] - x))) {
                idx--;
            }
        vector<int> res;
        vector<int> ls;
        vector<int> rs;
        int i = idx - 1;
        int j = idx + 1;
        while ((i >= 0 || j < n) && --k > 0) {
            if (i == -1) {
                rs.push_back(arr[j++]);
                continue;
            }
            if (j == n) {
                ls.push_back(arr[i--]);
                continue;
            }
            int left = abs(arr[i] - x);
            int right = abs(arr[j] - x);
            if (left == right || left < right) {
                ls.push_back(arr[i--]);
            } else {
                rs.push_back(arr[j++]);
            }
        }
        // sort(res.begin(), res.end());
        reverse(ls.begin(), ls.end());
        for (int& ele: ls) {
            res.push_back(ele);
        }
        res.push_back(arr[idx]);
        for (int& ele: rs) {
            res.push_back(ele);
        }
        return res;
    }
};