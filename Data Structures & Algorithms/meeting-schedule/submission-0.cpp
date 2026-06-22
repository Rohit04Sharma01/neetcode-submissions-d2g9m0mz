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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a.end < b.end;
        });
        int n = intervals.size();
        for (int i = 1; i < n; i += 1) {
            int s1 = intervals[i].start;
            int e1 = intervals[i].end;
            int s2 = intervals[i - 1].start;
            int e2 = intervals[i - 1].end;
            if (s2 < e1 && s1 < e2) {
                return false;
            }
        }
        return true;
    }
};
