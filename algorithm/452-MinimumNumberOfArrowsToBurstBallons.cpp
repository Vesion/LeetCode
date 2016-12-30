#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy, same with 435-NonOverlappingIntervals
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), 
            [](const pair<int,int>& p1, const pair<int,int>& p2) {
                if (p1.first == p2.first) return p1.second < p2.second;
                return p1.first < p2.first;
            });
        int res = 0;
        long long pre_end = LONG_MIN;
        for (auto& p : points) {
            if (p.first <= pre_end) {
                pre_end = min(pre_end, (long long)p.second);
            } else {
                ++res;
                pre_end = p.second;
            }
        }
        return res;
    }   
};


int main() {
    Solution s;
    return 0;
}

