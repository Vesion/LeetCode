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

// Solution 1 : sort with starts
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& v1, const vector<int>& v2) {
                 if (v1[0] == v2[0]) return v1[1] < v2[1];
                 return v1[0] < v2[0];
             });
        int pre_end = INT_MIN;
        int res = 0;
        for (const auto& i : intervals) {
            if (i[0] < pre_end) {
                ++res;
                pre_end = min(pre_end, i[1]);
            } else pre_end = i[1];
        }
        return res;
    }
};


// Solution 2 : sort with ends
class Solution_2 {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),
            [](const Interval& i1, const Interval& i2) {
                if (i1.end != i2.end) return i1.end < i2.end;
                return i1.start > i2.start;
            });
        int res = 0;
        int end = INT_MIN;
        for (auto i : intervals) {
            if (i.start < end) ++res; // if found overlapping, remove the latter one
            else end = i.end;
        }
        return res;
    }
};


int main() {
    return 0;
}

