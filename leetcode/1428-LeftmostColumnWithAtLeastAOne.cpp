#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

// binay search, O(nlogn)
class Solution {
public:
    int m, n;
    int leftMostColumnWithOne(BinaryMatrix &mat) {
        auto v = mat.dimensions();
        m = v[0], n = v[1];
        int lower = 0, upper = n;
        while (lower < upper) {
            int mid = lower+(upper-lower)/2;
            if (hasone(mat, mid)) upper = mid;
            else lower = mid+1;
        }
        if (lower == n) return -1;
        return lower;
    }

    bool hasone(BinaryMatrix& mat, int col) {
        for (int i = 0; i < m; ++i) if (mat.get(i, col)) return true;
        return false;
    }
};

// O(n+n), from top-right to bottom-left
class Solution1 {
public:
    int leftMostColumnWithOne(BinaryMatrix &mat) {
        auto v = mat.dimensions();
        int m = v[0], n = v[1];
        int row = 0, col = n-1;
        int res = -1;
        while (row < m && col >= 0) {
            if (mat.get(row, col) == 1) {
                res = col;
                --col;
            } else {
                ++row;
            }
        }
        return res;
    }
};

int main() {

}