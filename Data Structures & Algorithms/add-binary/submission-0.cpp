class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            int digitA = i >= 0 ? a[i] - '0' : 0;
            int digitB = j >= 0 ? b[j] - '0' : 0;
            if (carry == 0) {
                if (digitA && digitB) {
                    res += '0';
                    carry = 1;
                } else if (!digitA && !digitB) {
                    res += '0';
                } else {
                    res += '1';
                }
            } else {
                if (digitA && digitB) {
                    res += '1';
                    carry = 1;
                } else if (!digitA && !digitB) {
                    res += '1';
                    carry = 0;
                } else {
                    res += '0';
                    carry = 1;
                }
            }
            i -= 1; j -= 1; 
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};