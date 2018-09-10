#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Binary Indexed Tree (or Fenwick Tree) is a practical structure for Cumulative Frequency Tables.
//
// Similar to SegmentTree, BIT can deal with sum querying (intervals) and updating (single point) both in O(logn) time,
// but BIT cannot deal with updating intevals effectively.
//
// http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
// http://blog.csdn.net/ljsspace/article/details/6671046


// Problem: Given an array (or a 2D matrix) of numbers, implement update() and sumRange()


// Version 1 : 1D array
class NumArray {
private:
    vector<int> nums, sums;
    int n;
    
    void add(int id, int val) {
        for (int i = id+1; i <= n; i += (i & -i)) sums[i] += val;
    }
    
    int query(int id) {
        int res = 0;
        for (int i = id+1; i > 0; i -= (i & -i)) res += sums[i];
        return res;
    }
    
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        n = nums.size();
        sums.resize(n+1);
        for (int i = 0; i < n; ++i) add(i, nums[i]);
    }
    
    void update(int i, int val) {
        add(i, val-nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return query(j) - query(i-1);
    }
};


// Version 2 : 2D matrix
class NumMatrix {
private:
    vector<vector<int>> nums, sums;
    int m, n;
    
    void add(int row, int col, int val) {
        for (int i = row+1; i <= m; i += (i & -i)) {
            for (int j = col+1; j <= n; j += (j & -j)) {
                sums[i][j] += val;
            }
        }
    }
    
    int query(int row, int col) {
        int res = 0;
        for (int i = row+1; i > 0; i -= (i & -i)) {
            for (int j = col+1; j > 0; j -= (j & -j)) {
                res += sums[i][j];
            }
        }
        return res;
    }
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        m = matrix.size(), n = matrix[0].size();
        nums = matrix;
        sums.resize(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) add(i, j, nums[i][j]);
    }
    
    void update(int row, int col, int val) {
        add(row, col, val-nums[row][col]);
        nums[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2, col2) - query(row1-1, col2) - query(row2, col1-1) + query(row1-1, col1-1);
    }
};


int main() {
    return 0;
}
