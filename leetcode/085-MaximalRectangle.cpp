#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : extend the stack solution in 'Largest Rectangle in Histogram' to 2D
// O(n^2) time
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> hs(n+1, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') ++hs[j];
                else hs[j] = 0;
            }
            res = max(res, histogram(hs));
        }
        return res;
    }

    // same to 084-LargestRectangleInHistogram.cpp
    int histogram(const vector<int>& hs) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < hs.size(); ++i) {
            while (!st.empty() && hs[i] < hs[st.top()]) {
                int h = hs[st.top()];
                st.pop();
                int w = st.empty() ? i : i-st.top()-1;
                res = max(res, h*w);
            }
            st.push(i);
        }
        return res;
    }
};

// Solution 2 : DP, O(n^2) time
// h[i] is the number of vertically successive '1's
// l[i]/r[i] is the farthest reachable distance with height h[i]
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0), l(n, n+1), r(n, n+1);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') ++h[j];
                else h[j] = 0;
            }
            int left = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') l[j] = min(l[j], ++left);
                else left = 0, l[j] = n+1;
            }
            int right = 0;
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') r[j] = min(r[j], ++right);
                else right = 0, r[j] = n+1;
            }
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] == '1')
                    res = max(res, h[j]*(r[j]+l[j]-1));
        }
        return res;
    }
};


int main() {
    return 0;
}
