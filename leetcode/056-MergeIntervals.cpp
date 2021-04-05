#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& i1, const vector<int>& i2) {
                 return i1[0] < i2[0];
             });
        for (const vector<int>& interval : intervals) {
            if (res.empty() || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else if (interval[0] <= res.back()[1]) {
                res.back()[1] = max(interval[1], res.back()[1]);
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
