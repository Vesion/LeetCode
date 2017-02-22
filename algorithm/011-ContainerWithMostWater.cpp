#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) return 0;
        int i = 0, j = height.size()-1;
        int res = 0;
        while (i < j) {
            int h = min(height[i], height[j]);
            res = max(res, h * (j-i));
            if (height[i] <= h) ++i; // move the shorter bar
            else --j;
        }
        return res;
    }
};


int main() {
    return 0;
}
