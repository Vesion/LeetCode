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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), 
            [](const Interval& i1, const Interval& i2) {
                if (i1.start == i2.start) return i1.end < i2.end;
                return i1.start < i2.start;
        });
        int res = 0;
        int n = intervals.size();
        for (int i = 0; i < n; ) {
            int j = i+1;
            while (j < n && intervals[j].start < intervals[i].end) {
                intervals[i].end = min(intervals[i].end, intervals[j].end);
                ++j;
                ++res;
            }
            i = j;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
