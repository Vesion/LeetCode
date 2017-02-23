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
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<long double, int> s;
            int coincide = 0, vertical = 1, same = 1;
            for (int j = i+1; j < n; ++j) {
                auto p1 = points[i], p2 = points[j];
                if (p1.x == p2.x) {
                    if (p1.y == p2.y) ++coincide;
                    else ++vertical;
                } else {
                    long double slope = (long double)(p1.y - p2.y) / (p1.x - p2.x); // use long double in case overflow
                    if (s.count(slope)) ++s[slope];
                    else s[slope] = 2;
                    same = max(same, s[slope]);
                }
                same = max(same, vertical);
            }
            res = max(res, same+coincide);
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
