#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
} Interval;

// in-place, TLE!!
vector<Interval> insert_inplace(vector<Interval>& intervals, Interval newInterval) {
    if (intervals.empty()) {
        intervals.push_back(newInterval);
        return intervals;
    }

    for (auto it = intervals.begin(); it != intervals.end(); ) {
        if (newInterval.end < it->start) {
            intervals.insert(it, newInterval);
            return intervals;
        } else if (newInterval.start > it->end) {
            ++it;
            continue;
        } else {
            newInterval.start = min(newInterval.start, it->start);
            newInterval.end = max(newInterval.end, it->end);
            it = intervals.erase(it);
        }
    }
    intervals.insert(intervals.end(), newInterval);
    return intervals;
}

// not in-place, faster!!
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    if (intervals.empty()) {
        result.push_back(newInterval);
        return result;
    }
    for (auto it = intervals.begin(); it != intervals.end(); ) {
        if (newInterval.end < it->start) {
            result.push_back(newInterval);
            while (it != intervals.end())
                result.push_back(*it++);
            return result;
        } else if (newInterval.start > it->end) {
            result.push_back(*it++);
            continue;
        } else {
            newInterval.start = min(newInterval.start, it->start);
            newInterval.end = max(newInterval.end, it->end);
            ++it;
        }
    }
    result.push_back(newInterval);
    return result;
}

int main() {
    vector<Interval> intervals{Interval(1, 2),Interval(3, 5),Interval(6, 7),Interval(10, 18)};
    for (auto i : insert(intervals, Interval(4, 11))) {
        cout << i.start << " " << i.end << endl;
    }
    return 0;
}
