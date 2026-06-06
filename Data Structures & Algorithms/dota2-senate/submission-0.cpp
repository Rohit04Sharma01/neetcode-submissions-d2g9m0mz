class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        int R_Vote = 0;
        int D_Vote = 0;
        int R = 0;
        int D = 0;
        for (char ch: senate) {
            q.push(ch);
            if (ch == 'R') R += 1;
            else D += 1;
        }
        while (q.size() > 1) {
            char ch = q.front(); q.pop();
            if (ch == 'R') {
                if (D_Vote > 0) {
                    D_Vote -= 1;
                    R -= 1;
                } else {
                    R_Vote += 1;
                    q.push('R');
                }
            } 
            if (ch == 'D') {
                if (R_Vote > 0) {
                    R_Vote -= 1;
                    D -= 1;
                } else {
                    D_Vote += 1;
                    q.push('D');
                }
            }
            if (R == 0 || D == 0) break;
            
        }
        return q.front() == 'R' ? "Radiant" : "Dire";
    }
};