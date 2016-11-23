#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <cfloat> 
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n <= 1) return n;
        unordered_map<double, int> slope_count;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            slope_count.clear();
            int coincident_points = 0, sameline_points = 1;

            for (int j = i+1; j < n; ++j) {
                double slope;
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y) {
                        ++coincident_points;
                        continue;
                    } else {
                        slope = numeric_limits<double>::infinity();
                    }
                } else {
                    slope = (double)(points[i].y-points[j].y) / (points[i].x-points[j].x);
                }

                if (slope_count.count(slope)) slope_count[slope] ++;
                else slope_count[slope] = 2;

                sameline_points = max(sameline_points, slope_count[slope]);
            }
            
            res = max(res, sameline_points + coincident_points);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<Point> p = {{0,0}, {1,1}, {2,2}};
    cout << s.maxPoints(p) << endl;
    return 0;
}

