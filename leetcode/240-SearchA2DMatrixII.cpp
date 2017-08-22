#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The classical search a 2D matrix problem
// http://articles.leetcode.com/searching-2d-sorted-matrix-part-ii

// Solution 1 : Search from top-right to bottom-left, O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) return true;
            if (target < matrix[i][j]) --j;
            else ++i;
        }
        return false;
    }
};


// Solution 2 : bianry search each row, O(mlogn), TLE
class Solution_2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i].front() <= target && target <= matrix[i].back()
                && binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        }
        return false;
    }
};


// Solution 3 : divide and conquer, quad partiotion, O(n^(log3))
//


// Solution 4 : improved binary partiotion, O((logn)^2)
//


int main() {
    return 0;
}

