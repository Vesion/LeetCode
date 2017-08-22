#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;
struct Point {
    ll x, y;
};

const int MAX = 1001;
const ll INTMAX = 0x7fffffffffffffff;
int N;
Point p[MAX];

int main() {
    cin >> N; 
    for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;
    sort(p, p+N, [](const Point& p1, const Point& p2) {
            if (p1.y == p2.y) return p1.x < p2.x;
            return p1.y < p2.y; });

    ll res = INTMAX;
    for (int i = 0; i+3 < N; ++i) {
        for (int j = i+1; j+2 < N; ++j) {
            if (p[j].x == p[i].x || p[j].y != p[i].y) continue;
            for (int k = j+1; k+1 < N; ++k) {
                if (p[k].y == p[i].y || p[k].x != p[i].x) continue;
                for (int l = k+1; l < N; ++l) {
                    if (p[l].y != p[k].y || p[l].x != p[j].x) continue;
                    ll area = (p[j].x-p[i].x) * (p[k].y-p[i].y);
                    if (area) res = min(res, area);
                }
            }
        }
    }

    if (res == INTMAX) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
