#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;


// Solution 1 : stack, similar to '084-LargestRectangleInHistogram'
class Solution_stack {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; 
        stack<int> st;
        int i  = 0;
        int result = 0;
        while (i < (int)height.size()) {
            if (st.empty() || height[i] <= height[st.top()])
                st.push(i++);
            else {
                int bottom = st.top(); st.pop();
                int local = st.empty() ? 0 : (min(height[st.top()], height[i]) - height[bottom]) * (i - st.top() - 1);
                result += local;
            }
        }
        return result;
    }
};


// Solution 2 : two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int result = 0;
        int leftMax = 0, rightMax = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) leftMax = height[left];
                else result += leftMax - height[left];
                ++left;
            } else {
                if (height[right] >= rightMax) rightMax = height[right];
                else result += rightMax - height[right];
                --right;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
