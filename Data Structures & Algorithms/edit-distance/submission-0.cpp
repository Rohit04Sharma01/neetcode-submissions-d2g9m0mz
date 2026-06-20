class Solution {
   public:
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();

        vector<int> curr(m + 1);
        vector<int> next(m + 1);

        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            curr[m] = n - i;

            for (int j = m - 1; j >= 0; j--) {
                if (w1[i] == w2[j]) {
                    curr[j] = next[j + 1];
                } else {
                    curr[j] = 1 + min({
                                      next[j],      // delete
                                      curr[j + 1],  // insert
                                      next[j + 1]   // replace
                                  });
                }
            }

            next = curr;
        }

        return next[0];
    }
};
