class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000"))
            return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string node = q.front();
                q.pop();

                if (node == target)
                    return moves;

                for (int i = 0; i < 4; i++) {
                    char original = node[i];

                    // Rotate wheel forward
                    node[i] = (original == '9') ? '0' : original + 1;
                    if (!visited.count(node)) {
                        visited.insert(node);
                        q.push(node);
                    }

                    // Rotate wheel backward
                    node[i] = (original == '0') ? '9' : original - 1;
                    if (!visited.count(node)) {
                        visited.insert(node);
                        q.push(node);
                    }

                    // Restore original digit
                    node[i] = original;
                }
            }

            moves++;
        }

        return -1;
    }
};