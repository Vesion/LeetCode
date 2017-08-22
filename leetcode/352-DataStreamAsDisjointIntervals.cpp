#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
    vector<Interval> intervals;

public:
    SummaryRanges() { }
    
    void addNum(int val) {
        if (intervals.empty()) {
            intervals.push_back(Interval(val, val));
            return;
        }

        auto i = upper_bound(intervals.begin(), intervals.end(), val, [](const int lhs, const Interval rhs) { return lhs < rhs.start; });

        if (i == intervals.end()) {
            auto last = intervals.end() - 1;
            if (val <= last->end) return;
            if (val == last->end + 1) last->end += 1;
            else intervals.push_back(Interval(val, val));
        }
        else if (i == intervals.begin()) {
            auto first = intervals.begin();
            if (val == first->start - 1) first->start -= 1;
            else intervals.insert(first, Interval(val, val));
        }
        else {
            auto prev = i - 1;
            if (val <= prev->end) return;
            if (val == prev->end + 1) {
                if (val == i->start - 1) { // merge
                    i->start = prev->start;
                    intervals.erase(prev);
                } else {
                    prev->end += 1;
                }
            } else {
                if (val == i->start - 1) i->start -= 1;
                else intervals.insert(i, Interval(val, val));
            }
        }
    }
    
    vector<Interval> getIntervals() {
        return intervals;    
    }
};

int main() {
    vector<int> nums = {1, 3, 7, 2, 6};
    SummaryRanges obj;
    for (auto &i : nums) {
        obj.addNum(i);
        vector<Interval> r = obj.getIntervals();
        for (auto &i : r) cout << "[" << i.start << ", " << i.end << "] ";
        cout << endl;
    }
    return 0;
}
