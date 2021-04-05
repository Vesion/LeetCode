#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/

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


int main() {
    return 0;
}
