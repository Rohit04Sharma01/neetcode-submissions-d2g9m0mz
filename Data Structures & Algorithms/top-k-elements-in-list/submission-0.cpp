class Solution {
    typedef pair<int, int> p;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (int& n: nums) {
            ump[n] += 1;
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        for (auto [first, second]: ump) {
            pq.push({second, first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};