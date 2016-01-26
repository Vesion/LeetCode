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

bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.empty())
        return result;
    sort(intervals.begin(), intervals.end(), compare);
    int start = intervals[0].start, end = intervals[0].end;
    for (int i = 0; i < intervals.size(); ++i) {
        if (intervals[i].start > end) {
            result.push_back(Interval(start, end));
            start = intervals[i].start;
        } 
        end = max(intervals[i].end, end);
    }
    result.push_back(Interval(start, end));
    return result;
}

int main() {
    //vector<Interval> intervals{Interval(1, 3),Interval(2, 6),Interval(6, 10),Interval(10, 18)};
    vector<Interval> intervals{Interval(1, 4), Interval(2, 3)};
    for (auto i : merge(intervals)) {
        cout << i.start << " " << i.end << endl;
    }
    return 0;
}
