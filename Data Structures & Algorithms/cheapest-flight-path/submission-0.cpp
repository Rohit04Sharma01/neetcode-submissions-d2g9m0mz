class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // dist[node][remainingFlights]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        // {cost, {node, remainingFlights}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;

        dist[src][k + 1] = 0;
        pq.push({0, {src, k + 1}});

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int cost = curr.first;
            int node = curr.second.first;
            int remaining = curr.second.second;

            // Ignore stale states
            if (cost > dist[node][remaining])
                continue;

            if (node == dst)
                return cost;

            if (remaining == 0)
                continue;

            for (auto &[next, price] : adj[node]) {

                int newCost = cost + price;

                if (newCost < dist[next][remaining - 1]) {
                    dist[next][remaining - 1] = newCost;
                    pq.push({newCost, {next, remaining - 1}});
                }
            }
        }

        return -1;
    }
};