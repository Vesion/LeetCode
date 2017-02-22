#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : stack
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        stack<int> st;
        int res = 0;
        for (int i = 0; i < (int)height.size(); ) {
            if (st.empty() || height[i] <= height[st.top()]) st.push(i++);
            else {
                int low = height[st.top()];
                st.pop();
                if (st.empty()) continue;
                int high = min(height[i], height[st.top()]); // the bar is decided by the lower one of left and right
                res += (high-low) * (i-st.top()-1);
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

