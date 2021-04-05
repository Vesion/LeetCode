#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Greedy
// The new coming meeting-i must occupy a room, if a previous meeting-j ends before meeting-i starts,
// meeting-i could reuse meeting-j's room, otherwise meeting-i should open a new room.
// Use min-heap to get meeting-j which has the earliest ending time before meeting-i.
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& i1, const vector<int>& i2) {
                 if (i1[0] == i2[0]) return i1[1] < i2[1];
                 return i1[0] < i2[0];
             });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const vector<int>& i : intervals) {
            if (!pq.empty() && i[0] >= pq.top()) pq.pop();
            pq.push(i[1]);
        }
        return pq.size();
    }
};


// Similar to 732-MyCalendarIII
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t[0]]++, m[t[1]]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }
};


int main() {
    Solution s;
    vector<Interval> is = {{2,15},{4,9},{9,29},{16,23},{36,45}};
    cout << s.minMeetingRooms(is) << endl;
    return 0;
}
