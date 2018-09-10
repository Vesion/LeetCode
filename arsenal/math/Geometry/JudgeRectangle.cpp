#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set> 
using namespace std;

// http://hihocoder.com/problemset/problem/1040
// Problem:
//      Given 4 line segments, judge if they can form a rectangle or not.
// Solution:
//      First check there are only 4 distinct points,
//      Then check parallel and vertical relationships.


struct Point {
    int x, y;
    bool operator<(const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
    Point operator-(const Point& p) const { return {x-p.x, y-p.y}; }
};


// cross product 叉积
bool parallel(Point v1, Point v2) {
    return v1.x * v2.y - v2.x * v1.y == 0;
}

// point product 点积
bool vertiacal(Point v1, Point v2) {
    return v1.x * v2.x + v1.y * v2.y == 0;
}

bool solve() {
    vector<pair<Point, Point>> lines(4);
    set<Point> s;
    for (int i = 0; i < 4; ++i) {
        cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
        s.insert(lines[i].first);
        s.insert(lines[i].second);
    }
    // Condition 1 : there must be only 4 points
    if (s.size() != 4) return false;

    // Condition 2 : choose line0, for other 3 lines, there must be one line parallel with line0, two lines vertical with line0
    int p = 0, v = 0;
    for (int i = 1; i < 4; ++i) {
        if (parallel(lines[0].first-lines[0].second, lines[i].first-lines[i].second)) ++p;
        if (vertiacal(lines[0].first-lines[0].second, lines[i].first-lines[i].second)) ++v;
    }
    if (p == 1 && v == 2) return true;
    return false;
}

int main() {
    int T; cin >> T;    
    while (T--) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

