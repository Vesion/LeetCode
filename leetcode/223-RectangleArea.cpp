#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int bottom = max(B, F);
        int right = min(C, G);
        int top = min(D, H);
        int overlap = (left < right && bottom < top) ? (right-left) * (top-bottom) : 0;
        return ((A-C)*(B-D)) + ((E-G)*(F-H)) - overlap;
    }
};


int main() {
    return 0;
}
