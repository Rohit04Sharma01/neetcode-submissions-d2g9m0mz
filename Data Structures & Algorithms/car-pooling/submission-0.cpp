class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(), trips.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        // {to, passengers}

        for (auto &trip : trips) {

            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            // Drop passengers
            while (!pq.empty() && pq.top().first <= from) {
                capacity += pq.top().second;
                pq.pop();
            }

            if (capacity < passengers)
                return false;

            capacity -= passengers;

            pq.push({to, passengers});
        }

        return true;
    }
};