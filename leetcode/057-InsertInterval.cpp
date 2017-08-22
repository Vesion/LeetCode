#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        int i = 0;
        while (i < n) {
            if (intervals[i].end < newInterval.start) // push those who go front of newInterval
                res.push_back(intervals[i++]);
            else if (intervals[i].start > newInterval.end) // break to push newInterval and the rest
                break;
            else { // merge newInterval and those overlapping with it
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                ++i;
            }
        }
        res.push_back(newInterval);
        while (i < n) res.push_back(intervals[i++]);
        return res;
    }
};


int main() {
    return 0;
}
