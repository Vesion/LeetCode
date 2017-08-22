#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1 : from top-right to left-bottom, O(m+n)
class Solution {
public:
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n-1;
        int count = 0;
        while (i < m && j >= 0) {
            if (matrix[i][j] < target) ++i;
            else if (matrix[i][j] > target) --j;
            else { ++count; --j;}
        }
        return count;
    }
};


// Solution 2 : first binary search column, then binary search row, O(logm * logn)
class Solution_2 {
private:
    int count = 0;
    void search(vector<vector<int>>& matrix, int target, int top, int bottom) {
        if (top >= bottom) return;
        int mid = top + (bottom-top)/2;
        if (matrix[mid].front() <= target && target <= matrix[mid].back())
            if (binary_search(matrix[mid].begin(), matrix[mid].end(), target)) ++count;
        search(matrix, target, mid+1, bottom);
        search(matrix, target, top, mid);
    }

public:
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        search(matrix, target, 0, matrix.size());
        return count;
    }
};

int main() {
    vector<vector<int>> matrix = { 
        { 1, 3, 5, 7 },
        { 2, 4, 7, 8 },
        { 3, 5, 9, 10 }
    };

    Solution s;
    cout << s.searchMatrix(matrix, 3) << endl;

    Solution_2 s2;
    cout << s2.searchMatrix(matrix, 3) << endl;
    return 0;
}
