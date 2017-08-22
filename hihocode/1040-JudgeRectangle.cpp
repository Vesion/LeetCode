#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set> 
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const { return x < p.x || (x == p.x && y < p.y); }
    Point operator-(const Point& p) const { return {x-p.x, y-p.y}; }
};


bool parallel(Point v1, Point v2) {
    return v1.x * v2.y == v1.y * v2.x;
}

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
    if (s.size() != 4) return false;
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
