#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : similar to 056-MergeIntervals
class Solution_1 {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        vector<pair<int,int>> intervals;
        for (int& t : timeSeries) {
            if (intervals.empty() || t > intervals.back().second) intervals.push_back({t, t+duration});
            else intervals.back().second = max(intervals.back().second, t+duration);
        }
        int res = 0;
        for (auto& p : intervals) res += p.second-p.first;
        return res;
    }
};


// Solution 2 : no need to simulate intervals
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int preEnd = INT_MIN;
        int res = 0;
        for (int& t : timeSeries) {
            if (t > preEnd) {
                res += duration;
                preEnd = t+duration;
            }
            else if (t+duration > preEnd) {
                res += t+duration-preEnd;
                preEnd = t+duration;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
