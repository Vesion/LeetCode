#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// two pointers, one scans from left to right, the other the opposite
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while (left < right) {
            // the area is decided by the shorter line
            res = max(res, min(height[left], height[right]) * (right-left));

            // so we need to move the shorter line to get better result
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

