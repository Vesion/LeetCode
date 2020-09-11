#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& i1, const vector<int>& i2) {
                if (i1[0] == i2[0]) return i1[1] < i2[1];
                else return i1[0] < i2[0];
            });
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& interval : intervals) {
            if (!pq.empty() && interval[0] >= pq.top()) pq.pop();
            pq.push(interval[1]);
        }
        return pq.size();
    }
};


int main() {
    Solution s;
    vector<Interval> is = {{2,15},{4,9},{9,29},{16,23},{36,45}};
    cout << s.minMeetingRooms(is) << endl;
    return 0;
}
