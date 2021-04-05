#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// two pointers in polar system
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        int origin = 0;
        vector<double> polar;
        for (int i = 0; i < n; ++i) {
            int dx = points[i][0] - location[0];
            int dy = points[i][1] - location[1];
            if (dx == 0 && dy == 0) ++origin;  // count points same with location
            else {
                double v = get_angle(dx, dy);
                if (v < 0) v += 360;  // make angle in [0, 360)
                polar.push_back(v);
            }
        }
        sort(polar.begin(), polar.end());

        // duplicate sorted points to make it a cycle
        vector<double> cyc = polar;
        for (double& p : polar) p += 360;
        cyc.insert(cyc.end(), polar.begin(), polar.end());

        int res = 0;
        for (int i = 0, j = 0; i < cyc.size(); ++i) {
            while (j < i && (cyc[i]-cyc[j] > angle)) ++j;
            res = max(res, i-j+1);
        }
        return res + origin;
    }

    double get_angle(int dx, int dy) {
        return atan2(dy, dx) / M_PI * 180.0;
    }
};


int main() {

}