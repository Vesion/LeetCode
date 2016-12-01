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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval i1, const Interval i2) { return i1.start < i2.start; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
