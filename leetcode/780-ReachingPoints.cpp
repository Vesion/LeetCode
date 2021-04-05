#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Brute force, dfs in binary tree, stack overflow and TLE
class Solution0 {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return true;
        if (sx > tx || sy > ty) return false;
        return reachingPoints(sx+sy, sy, tx, ty) || reachingPoints(sx, sy+sx, tx, ty);
    }
};


// Starting from target point
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx < ty) ty %= tx;
            else tx %= ty;
        }
        return (sx == tx && sy <= ty && (ty-sy)%sx == 0) ||
               (sy == ty && sx <= tx && (tx-sx)%sy == 0);

    }
};

int main() {

}
