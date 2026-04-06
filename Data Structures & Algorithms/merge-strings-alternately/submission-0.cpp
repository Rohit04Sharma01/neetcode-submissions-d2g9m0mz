class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int n = word1.size();
        int m = word2.size();
        int turn = 0;
        string res = "";
        while (i < n || j < m) {
            if (j == m) {
                res += word1.substr(i);
                break;
            }
            if (i == n) {
                res += word2.substr(j);
                break;
            }
            if (!turn) {
                res += word1[i++];
            } else {
                res += word2[j++];
            }
            turn = !turn;
        }
        return res;
    }
};