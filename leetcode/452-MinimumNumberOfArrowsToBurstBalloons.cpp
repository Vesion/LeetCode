#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy, same with 435-NonOverlappingIntervals
class Solution {
public:
    using ll = long long;
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const vector<int>& p1, const vector<int>& p2) {
                 if (p1[0] == p2[0]) return p1[1] < p2[1];
                 return p1[0] < p2[0];
             });
        ll pre_end = LONG_MIN;
        int overlaps = 0;
        for (const vector<int>& p : points) {
            if (p[0] <= pre_end) {
                ++overlaps;
                pre_end = min(pre_end, ll(p[1]));
            } else pre_end = p[1];
        }
        return points.size()-overlaps;
    }
};


int main() {
    return 0;
}

