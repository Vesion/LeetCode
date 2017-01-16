#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// stack, similar to 042-TrappingRainWater
// For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. 
// If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. 
//
// So, we maintain a monotonic increasing stack, when we find a bar shorter than its top, we pop a bar as x
// then current shorter bar is x's right border, where is x's left border? the new top one (or -1 if stack is empty)
// so the area for rectangle of x as height is x * (right-left)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        for (int i = 0; i < (int)heights.size(); ) {
            if (st.empty() || heights[i] >= heights[st.top()])
                st.push(i++);
            else {
                int h = heights[st.top()]; // the x bar
                st.pop(); // try to get left border index
                int w = st.empty() ? i :  i-st.top()-1;
                res = max(res, h*w);
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
