class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        if (total_cost > total_gas) return -1;
        int n = gas.size();
        int res = 0;
        int tank = 0;
        for (int i = 0; i < n; i++) {
            tank += gas[i];
            tank -= cost[i];
            if (tank < 0) {
                tank = 0;
                res = i + 1;
            }
        }   
        return res;
    }
};