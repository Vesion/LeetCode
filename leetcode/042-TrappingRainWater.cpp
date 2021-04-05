#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 042-TrappingRainWater.cpp
// 084-LargestRectangleInHistogram.cpp
// 085-MaximalRectangle.cpp

// Solution 1 : mono decreasing stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int low = height[st.top()];
                st.pop();
                if (st.empty()) break;
                int high = min(height[i], height[st.top()]);
                res += (high-low) * (i-st.top()-1);
            }
            st.push(i);
        }
        return res;
    }
};

// Solution 2 : two-pointers
// Scan from two ends to middle, record leftMax and rightMax height
class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int lmax = 0, rmax = 0;
        int l = 0, r = n-1;
        while (l <= r) {
            if (height[l] < height[r]) {
                if (height[l] >= lmax) lmax = height[l];
                else res += lmax - height[l];
                ++l;
            } else {
                if (height[r] >= rmax) rmax = height[r];
                else res += rmax - height[r];
                --r;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
