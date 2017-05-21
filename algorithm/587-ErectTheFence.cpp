#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    vector<Point> buckets[105];

    vector<Point> outerTrees(vector<Point>& points) {
        for (auto& p : points) buckets[p.x].push_back(p);
        for (int i = 0; i <= 100; ++i) sort(buckets[i].begin(), buckets[i].end(), [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
        int beg = 0;
        for (int i = 0; i <= 100; ++i) if (!buckets[i].empty()) { beg = i; break; }
        int end = 100;
        for (int i = 100; i >= 0; --i) if (!buckets[i].empty()) { end = i; break; }
        vector<Point> res;
        for (auto& p : buckets[beg]) res.push_back(p);
        if (beg == end) return res;
        for (auto& p : buckets[end]) res.push_back(p);


        auto last = buckets[beg].back();
        for (int cur = beg+1; cur != end; ++cur) {
            if (buckets[cur].empty()) continue;
            Point p = buckets[cur].back();
            bool valid = true;
            for (int i = cur+1; i <= end; ++i) {
                if (buckets[i].empty()) continue;
                if (cross(vertex(p, last), vertex(buckets[i].back(), last)) > 0) { valid = false; break; }
            }
            if (valid) {
                res.push_back(p); buckets[cur].pop_back();
                last = p;
            }
        }
        last = buckets[beg].front();
        for (int cur = beg+1; cur != end; ++cur) {
            if (buckets[cur].empty()) continue;
            Point p = buckets[cur].front();
            bool valid = true;
            for (int i = cur+1; i <= end; ++i) {
                if (buckets[i].empty()) continue;
                if (cross(vertex(p, last), vertex(buckets[i].front(), last)) < 0) { valid = false; break; }
            }
            if (valid) {
                res.push_back(p); buckets[cur].pop_back();
                last = p;
            }
        }
        return res;
    }

    int cross(const Point& p1, const Point& p2) {
        return p1.x*p2.y - p1.y*p2.x;
    }

    Point vertex(const Point& p1, const Point& p2) {
        return Point(p1.x-p2.x, p1.y-p2.y);
    }
};


int main() {
    Solution s;
    //vector<Point> points = { { 1,1 },{ 2,2 },{ 2,0 },{ 2,4 },{ 3,3 },{ 4,2 } };
    vector<Point> points = {{1,5}};
    auto r = s.outerTrees(points);
    for (auto& e : r) cout << e.x << " " << e.y << endl; cout << endl; 
    return 0;
}
