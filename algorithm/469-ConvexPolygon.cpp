#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// calculate cross product of two vectors compose three consecutive points
// http://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
class Solution {
public:
    bool isConvex(vector<vector<int>>& p) {
        long n = p.size(), last = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            long x1 = p[i%n][0], y1 = p[i%n][1];
            long x2 = p[(i+1)%n][0], y2 = p[(i+1)%n][1];
            long x3 = p[(i+2)%n][0], y3 = p[(i+2)%n][1];
            cur = (x2-x1)*(y3-y2) - (x3-x2)*(y2-y1);
            if (cur) {
                if (cur*last < 0) return false;
                last = cur;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> p = {{0,0}, {0,0}};
    cout << s.isConvex(p) <<endl;
    return 0;
}