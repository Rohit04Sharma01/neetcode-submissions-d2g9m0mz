class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<vector<int>> arr;

        // store {enqueueTime, processingTime, index}
        for (int i = 0; i < tasks.size(); i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(arr.begin(), arr.end());

        // {processingTime, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> result;

        long long time = 0;
        int i = 0;
        int n = arr.size();

        while (i < n || !pq.empty()) {

            // CPU idle → jump to next task time
            if (pq.empty() && time < arr[i][0]) {
                time = arr[i][0];
            }

            // push all available tasks
            while (i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            auto [processTime, idx] = pq.top();
            pq.pop();

            result.push_back(idx);
            time += processTime;
        }

        return result;
    }
};