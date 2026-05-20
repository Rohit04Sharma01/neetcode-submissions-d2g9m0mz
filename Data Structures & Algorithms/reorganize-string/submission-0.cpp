class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &[ch, count] : freq) {
            pq.push({count, ch});
        }

        string res = "";

        pair<int, char> prev = {0, '#'}; 

        while (!pq.empty()) {

            auto [count, ch] = pq.top();
            pq.pop();

            res += ch;
            count--;

            // push back previous character if still available
            if (prev.first > 0) {
                pq.push(prev);
            }

            // current becomes previous
            prev = {count, ch};
        }

        // check if reorganization succeeded
        return res.size() == s.size() ? res : "";
    }
};