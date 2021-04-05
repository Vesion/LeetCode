#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <cfloat>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        constexpr double kMax = numeric_limits<double>::max();
        int n = points.size();
        int res = 1;
        for (int i = 0; i < n; ++i) {
            int x0 = points[i][0], y0 = points[i][1];
            unordered_map<double, int> lines;
            for (int j = i+1; j < n; ++j) {
                int x1 = points[j][0], y1 = points[j][1];
                double slop = 0;
                if (x0 == x1) slop = kMax;
                else slop = (y1-y0)*1.0 / (x1-x0);
                ++lines[slop];
            }
            for (const auto& p : lines) res = max(res, p.second+1);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<Point> p = { { 0,0 },{ 94911151,94911150 },{ 94911152,94911151 } };
    cout << s.maxPoints(p) << endl;
    return 0;
}
