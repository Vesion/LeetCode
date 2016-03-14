#include <iostream>
using namespace std;

struct Rect {
    int x1, y1, x2, y2;
    Rect(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
    int area() { return (x2-x1) * (y2-y1); }
};


// Solution 1 : firstly judge if they are intersected, then figure out how they overlap, trivial
bool intersected(const Rect& r1, const Rect& r2) {
    return !(r1.x2 <= r2.x1 || r1.x1 >= r2.x2 || r1.y2 <= r2.y1 || r1.y1 >= r2.y2);
}

int computeArea_judge(int A, int B, int C, int D, int E, int F, int G, int H) {
    Rect r1(A, B, C, D), r2(E, F, G, H);
    int total = r1.area() + r2.area();
    if (!intersected(r1, r2)) return total; // no overlap area
    int ow, oh; // overlap width and height
    if (r1.x1 <= r2.x1) {
        if (r2.x2 <= r1.x2) ow = r2.x2 - r2.x1;
        else ow = r1.x2 - r2.x1;
    }
    else {
        if (r1.x2 < r2.x2) ow = r1.x2 - r1.x1;
        else ow = r2.x2 - r1.x1;
    }
    if (r1.y1 <= r2.y1) {
        if (r2.y2 <= r1.y2) oh = r2.y2 - r2.y1;
        else oh = r1.y2 - r2.y1;
    }
    else {
        if (r1.y2 < r2.y2) oh = r1.y2 - r1.y1;
        else oh = r2.y2 - r1.y1;
    }
    return total - ow*oh;
}


// Solution 2 : no intersection judge
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    Rect r1(A, B, C, D), r2(E, F, G, H);
    int left = max(r1.x1, r2.x1);
    int right = min(r1.x2, r2.x2);
    int bottom = max(r1.y1, r2.y1);
    int top = min(r1.y2, r2.y2);
    int overlap = 0;
    if (right > left && top > bottom) overlap = (right-left) * (top-bottom);
    return (r1.area() + r2.area() - overlap);
}

int main() {
    cout << computeArea_judge(-2, -2, 2, 2, -3, 1, -1, 3) << endl;
    cout << computeArea(-2, -2, 2, 2, -3, 1, -1, 3) << endl;
    return 0;
}
