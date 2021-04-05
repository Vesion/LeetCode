#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(N^2) space
class Solution_1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> cp = matrix;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cp[i][j] = matrix[n-j-1][i];
        matrix = cp;
    }
};


// Solution 2 : in place
// 1) First reverse up to down, then swap the symmetry (clockwise rotate)
// or
// 2) First reverse left to right, then swap the symmetry (anticlockwise rotate)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end()); // reverse up to down
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};

int main() {
    Solution s;
    return 0;
}

