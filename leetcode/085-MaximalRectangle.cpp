#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 042-TrappingRainWater.cpp
// 084-LargestRectangleInHistogram.cpp
// 085-MaximalRectangle.cpp

// Solution 1 : extend the stack solution in 'Largest Rectangle in Histogram' to 2D
// O(n^2) time
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> h(n+1, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != '0') ++h[j];
                else h[j] = 0;
            }
            res = max(res, max_histogram(h));
        }
        return res;
    }

    int max_histogram(const vector<int>& hs) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < hs.size(); ++i) {
            while (!st.empty() && hs[i] < hs[st.top()]) {
                const int h = hs[st.top()];
                st.pop();
                const int w = st.empty() ? i : i-st.top()-1;
                res = max(res, h*w);
            }
            st.push(i);
        }
        return res;
    }
};

// Solution 2 : DP, O(n^2) time
// height[i] is the number of successive '1's above
// left[i] & right[i] is the farthest position the rectangle can reach with height[i]
class Solution1 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n-1);
        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') height[j] += 1;
                else height[j] = 0;
            }
            // With height[j], how leftward far can the rect be
            int cur_left = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                } else {
                    cur_left = j+1;
                    left[j] = 0;
                }
            }
            // With height[j], how rightward far can the rect be
            int cur_right = n-1;
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    cur_right = j-1;
                    right[j] = n;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    max_area = max(max_area, (right[j] - left[j] + 1) * height[j]);
                }
            }
        }
        return max_area;
    }
};


int main() {
    return 0;
}
