#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : stack
// For every bar, find how much water can be held in this level
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < (int)height.size(); ) {
            if (st.empty() || height[i] <= height[st.top()]) st.push(i++);
            else {
                int bottom = height[st.top()]; // get bottom bar height
                st.pop();
                if (st.empty()) continue;
                int w = i - st.top() - 1; // water area width
                int h = min(height[i], height[st.top()]) - bottom; // water area height
                res += w * h;
            }
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
    Solution s;
    return 0;
}

