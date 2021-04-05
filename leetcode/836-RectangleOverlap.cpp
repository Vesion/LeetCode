#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    struct Rect {
        int x1, y1, x2, y2;
        Rect(const vector<int>& v)
            : x1(v[0]), y1(v[1]), x2(v[2]), y2(v[3]) {}
    };
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Rect r1(rec1), r2(rec2);
        // check if the rectangle's area is > 0
        if (r1.x1 == r1.x2 || r1.y1 == r1.y2 || r2.x1 == r2.x2 || r2.y1 == r2.y2) return false;
        // check if the greatest x of r1 is less than the smallest x of r2 ...
        return !(r1.x1 >= r2.x2 ||
                 r1.x2 <= r2.x1 ||
                 r1.y1 >= r2.y2 ||
                 r1.y2 <= r2.y1);
    }
};

int main() {

}