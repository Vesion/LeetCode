#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// Solution 1 : brute-force, O(n^2) time, O(n) space
// 对点i，遍历其他点，找出所有斜率，若斜率相同则在同一直线。用一个哈希表存，key为斜率，value为该斜率直线上的点数。统计最大值。
int maxPoints(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return n;
    int result = 0;
    unordered_map<double, int> slope_count;

    for (int i = 0; i < n-1; ++i) {
        slope_count.clear();
        int coincident_points = 0;
        int sameline_points = 1;

        for (int j = i+1; j < n; ++j) {
            double slope;
            if (points[j].x == points[i].x) {
                slope = std::numeric_limits<double>::infinity();
                if (points[j].y == points[i].y) {
                    ++coincident_points;
                    continue;
                }
            } else {
                slope = 1.0 * (points[j].y-points[i].y) / (points[j].x-points[i].x);
            }

            if (slope_count.count(slope)) ++slope_count[slope];
            else slope_count[slope] = 2;

            sameline_points = max(sameline_points, slope_count[slope]);
        }

        result = max(result, coincident_points + sameline_points);
    }
    return result;
}

int main() {
    vector<Point> points = {
        Point(0, 0),
        Point(1, 1),
        Point(1, -1),
        //Point(4, 1),
        //Point(5, 1),
        //Point(6, 1),
        //Point(7, 1),
    };
    cout << maxPoints(points) << endl;
    return 0;
}
