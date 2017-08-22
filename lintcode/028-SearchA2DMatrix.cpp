#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n;

        while (left < right) {
            int mid = left + (right-left)/2;
            int num = matrix[mid/n][mid%n];
            if (num == target) return true;
            if (num < target) left = mid+1;
            else right = mid;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = { 
        { 1, 3, 5, 7 },
        { 10, 11, 16, 20 },
        { 23, 30, 34, 50 }
    };
    cout << s.searchMatrix(matrix, 0);
    return 0;
}
