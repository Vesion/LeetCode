#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : extend the stack solution in 'Largest Rectangle in Histogram' to 2D
// O(n^2) time


// Solution 2 : DP, O(n^2) time
//      height[i] is the number of successive '1's above plus the current one
//      left[i] & right[i] is value of left & right means the boundaries of the rectangle which contains the current point with a height of value height.
//      e.g.
//              0 0 1 1 1 0
//              0 0 1 1 1 0
//                    ^
//                    height[i] = 2, left[i] = 2, right[i] = 5, area = (5-2)*2 = 6
//
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), // the number of consecutive '1's vertically
                    left(n, 0),   // left bounder of current rectangle
                    right(n, n);  // right bounder of current rectangle
        int result = 0;
        
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n; 
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j+1; // [left, right)
                }
            }
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j; // [left, right)
                }
            }
            for (int j = 0; j < n; ++j) {
                result = max(result, (right[j]-left[j])*height[j]);
            }
        }

        return result;
    }
};


int main() {
    return 0;
}

