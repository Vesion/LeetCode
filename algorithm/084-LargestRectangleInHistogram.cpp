#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// stack
// Similar to 042-TrappingRainWater
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        heights.push_back(0);
        stack<int> st;
        int res = 0;
        for (int i = 0; i < (int)heights.size(); ) {
            if (st.empty() || heights[i] > heights[st.top()]) st.push(i++);
            else {
                int h = heights[st.top()]; 
                st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                res = max(res, h * w);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
