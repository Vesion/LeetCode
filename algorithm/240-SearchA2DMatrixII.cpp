#include <iostream>
#include <vector>
using namespace std;

// the famous 'search in sorted 2D matrix' problem
// here talks a lot about it:
// http://articles.leetcode.com/searching-2d-sorted-matrix-part-ii

// Solution 1 : linear, from right-top, if smaller than target, go down; else, go left. O(m+n) time
bool searchMatrix_linear(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int i = 0, j = n-1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] > target) --j;
        else ++i;
    }
    return false;
}


// Solution 2 : quad partition, O(n^lg3) time
// we do not implement here


// Solution 3 : binary search, for each row, do a binary search inside it. O(mlgn) time
bool binarySearch(vector<int>& v, int target) {
    int l = 0, r = v.size();
    while (l < r) {
        int m = l + (r-l)/2;
        if (v[m] == target) return true;
        if (v[m] > target) r = m;
        else l = m+1;
    }
    return false;
}

bool searchMatrix_bs(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    for (int i = 0; i < m; ++i)
        if (binarySearch(matrix[i], target)) return true;
    return false;
}


// Solution 3 v2 : do binary search in row, then do binary search in column. O(lgm * lgn) time
bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
    if (top >= bottom)
        return false;
    int mid = top + (bottom - top) / 2;
    if (matrix[mid].front() <= target && target <= matrix[mid].back())
        if (binarySearch(matrix[mid], target)) return true;
    if (searchMatrix(matrix, target, top, mid)) return true;
    if (searchMatrix(matrix, target, mid+1, bottom)) return true;
    return false;
}

bool searchMatrix_bsm(vector<vector<int>>& matrix, int target) {
    return searchMatrix(matrix, target, 0, matrix.size());
}

int main() {
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    cout << searchMatrix_linear(matrix, 5) << endl;
    cout << searchMatrix_bs(matrix, 19) << endl;
    cout << searchMatrix_bsm(matrix, 19) << endl;
    return 0;
}
