#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll cross(Point& a, Point& b, Point& c, Point& d) {
    ll x1 = b.x-a.x, y1 = b.y-a.y;
    ll x2 = d.x-c.x, y2 = d.y-c.y;
    return x1*y2 - x2*y1;
}


int main() {
    int cases; cin >> cases;
    while (cases--) {
        Point p, a, b, c;
        cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        ll c1 = cross(a, p, a, b), c2 = cross(b, p, b, c), c3 = cross(c, p, c, a);
        if ((c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
