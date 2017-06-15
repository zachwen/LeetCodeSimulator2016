#include "leetcode.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// leetcode 253

struct IntervalEarly {
    bool operator()(Interval a, Interval b) {
        if (a.start < b.start) return 1;
        else if (a.start > b.start) return 0;
        else return a.end <= b.end;
    }
} IntervalEarly;
 
struct IntervalEndEarly {
    bool operator()(Interval a, Interval b) {
        return a.end >= b.end;
    }
};

int minMeetingRooms(vector<Interval>& intervals) {
    if (!intervals.empty())
        sort(intervals.begin(), intervals.end(), IntervalEarly);
    priority_queue<Interval, vector<Interval>, IntervalEndEarly> pq;
    int roomNumber = 0;
    for (auto interval : intervals) {
        if (pq.empty())
            ++roomNumber;
        else {
            Interval i = pq.top();
            if (i.end <= interval.start) pq.pop();
            else ++roomNumber;
        }
        pq.push(interval);
    }
    return roomNumber;
}