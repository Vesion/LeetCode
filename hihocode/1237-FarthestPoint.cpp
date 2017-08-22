#include <iostream>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const double eps = 1e-6;

int main() {
    ios::sync_with_stdio(false);
    double x, y, r;
    cin >> x >> y >> r;

    int rx, ry;
    double best = 0;
    int minx = ceil(x-r), maxx = floor(x+r);

    for (int tx = maxx; tx >= minx; --tx) {
        double d = sqrt(r*r - (x-tx)*(x-tx));
        int ty = floor(y+d);
        double dist = (tx-x)*(tx-x) + (ty-y)*(ty-y);
        if (dist - best > eps) {
            rx = tx; ry = ty;
            best = dist;
        }

        ty = ceil(y-d);
        dist = (tx-x)*(tx-x) + (ty-y)*(ty-y);
        if (dist - best > eps) {
            rx = tx; ry = ty;
            best = dist;
        }

    }
    cout << rx << " " << ry << endl;
    
    return 0;
}

