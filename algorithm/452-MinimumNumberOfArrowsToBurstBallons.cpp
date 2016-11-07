#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), 
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                if (p1.first == p2.first) return p1.second < p2.second;
                return p1.first < p2.first; });
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ) {
            int j = i+1;
            while (j < n && points[j].first <= points[i].second) {
                points[i].second = min(points[i].second, points[j].second);
                ++j;
            }
            ++res;
            i = j;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
