#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <map> 
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> index(n, 0);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&intervals](int i1, int i2) { return intervals[i1].start < intervals[i2].start; });
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(index.begin(), index.end(), intervals[i].end, [&intervals](int i, int end) { return intervals[i].start < end; });
            if (it != index.end()) res[i] = *it;
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

