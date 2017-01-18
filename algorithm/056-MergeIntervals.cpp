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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if (i1.start == i2.start) return i1.end < i2.end;
            return i1.start < i2.start;
        });
        vector<Interval> res;
        for (Interval& i : intervals) {
            if (res.empty() || i.start > res.back().end) res.push_back(i);
            else res.back().end = max(res.back().end, i.end);
        }
        return res;
    }
};


int main() {
    return 0;
}
