#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// calculate cross product of two vectors compose three consecutive points
// http://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long cur = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            long long x0 = points[i][0], y0 = points[i][1];
            long long x1 = points[(i+1)%n][0], y1 = points[(i+1)%n][1];
            long long x2 = points[(i+2)%n][0], y2 = points[(i+2)%n][1];
            cur = (x1-x0)*(y2-y1) - (x2-x1)*(y1-y0);

            // be careful here, we must ensure cur is not 0
            // because when cur is 0, it means three points are in same line, we shouldn't update pre here in case missing old pre
            if (cur) {
                if (cur*pre < 0) return false;
                pre = cur;
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<vector<int>> p = { { 0,0 },{ 0,1 },{ 1,1 },{ 2,1 },{ 2,2 },{ 2,3 },{ 3,3 },{ 3,0 } };
    //      ___
    //      | |
    //  ____| |
    // |______|
    //
    cout << s.isConvex(p) <<endl;
    return 0;
}
