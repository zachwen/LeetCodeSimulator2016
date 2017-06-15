/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// leetcode 252

struct IntervalEarly {
    bool operator () (Interval a, Interval b) {
        if (a.start < b.start) return 1;
        else if (a.start > b.start) return 0;
        else return (a.end <= b.end);
    }
} IntervalEarly;

bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), IntervalEarly);
    int end = 0;
    for (auto interval : intervals) {
        if (end > interval.start) return 0;
        end = interval.end;
    }
    return 1;
}