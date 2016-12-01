#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const Interval i1, const Interval i2) { return i1.start < i2.start; });
        priority_queue<int, vector<int>, greater<int>> q; // store each room's last end time
        q.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= q.top()) q.pop();
            q.push(intervals[i].end);
        }
        return q.size();
    }
};

int main() {
    Solution s;
    vector<Interval> is = {{2,15},{4,9},{9,29},{16,23},{36,45}};
    cout << s.minMeetingRooms(is) << endl;
    return 0;
}
