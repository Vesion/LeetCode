#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
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
        if (intervals.empty()) return {};
        int n = intervals.size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i){
            s.insert({intervals[i].start, i});
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            auto it = s.lower_bound({intervals[i].end, 0});
            if (it != s.end()) res[i] = it->second;
        }
        return res;
    }
};

int main() {

    return 0;
}
