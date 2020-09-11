#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 042-TrappingRainWater.cpp
// 084-LargestRectangleInHistogram.cpp
// 085-MaximalRectangle.cpp

// Solution 1 : stack
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int res = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                const int low = height[st.top()];
                st.pop();
                if (st.empty()) continue;
                const int high = min(height[i], height[st.top()]);
                res += (high - low) * (i-st.top()-1);
            }
            st.push(i);
        }
        return res;
    }
};

// Solution 2 : two-pointers
// Scan from two ends to middle, record leftMax and rightMax height
class Solution_2 {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (left <= right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) leftMax = height[left];
                else res += leftMax - height[left];
                ++left;
            } else {
                if (height[right] >= rightMax) rightMax = height[right];
                else res += rightMax - height[right];
                --right;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
