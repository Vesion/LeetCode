#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The classical search a 2D matrix problem

// Solution 1 : Search from top-right to bottom-left, O(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n-1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) ++x;
            else --y;
        }
        return false;
    }
};


// Solution 2 : Binary search rows then columns, O(logm * logn)
class Solution_2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, target, 0, matrix.size());
    }

    bool search(vector<vector<int>>& matrix, int target, int top, int bottom) {
        if (top >= bottom)
            return false;
        int mid = top + (bottom - top) / 2;
        if (matrix[mid].front() <= target && target <= matrix[mid].back())
            if (binary_search(matrix[mid].begin(), matrix[mid].end(), target)) return true;
        if (search(matrix, target, top, mid)) return true;
        if (search(matrix, target, mid+1, bottom)) return true;
        return false;
    }
};


int main() {
    return 0;
}

