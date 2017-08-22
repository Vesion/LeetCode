#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        if (heights.empty()) return 0;
        stack<int> s;
        heights.push_back(0);
        int result = 0;

        int i = 0;
        while (i < (int)heights.size()) {
            if (s.empty() || heights[i] > heights[s.top()])
                s.push(i++);
            else {
                int t = s.top();
                s.pop();
                result = max(result, heights[t]*(s.empty() ? i : i-s.top()-1));
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> heights = {1, 1};
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
