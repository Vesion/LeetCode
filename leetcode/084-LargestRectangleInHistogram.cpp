#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 042-TrappingRainWater.cpp
// 084-LargestRectangleInHistogram.cpp
// 085-MaximalRectangle.cpp
//
// mono-increasing stack
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
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                const int h = heights[st.top()];  // height
                st.pop();  // pop to get left bound, because its height must be smaller than height
                const int w = st.empty() ? i : i-st.top()-1;  // right bound is i
                res = max(res, h*w);
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> h({1,2,3});
    Solution s;
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}
