class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;

        for(char t : tasks)
            freq[t]++;

        priority_queue<int> pq;

        for(auto &[c,f] : freq)
            pq.push(f);

        queue<pair<int,int>> cooldown;
        int time = 0;

        while(!pq.empty() || !cooldown.empty()) {
            time++;

            if(!pq.empty()) {
                int cnt = pq.top();
                pq.pop();

                cnt--;

                if(cnt > 0)
                    cooldown.push({cnt, time + n});
            }

            if(!cooldown.empty() &&
            cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }

        return time;
    }
};