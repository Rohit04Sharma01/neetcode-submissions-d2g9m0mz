/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            if (a.start == b.start) {
                return a.end < b.end;
            }
            return a.start < b.start;
        });
        int count = 0;
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() <= intervals[i].start) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            count = max(count, (int) pq.size());
        }
        return count;
    }
};
