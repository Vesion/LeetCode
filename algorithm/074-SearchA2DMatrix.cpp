#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty())
        return false;
    int m = matrix.size(), n = matrix[0].size();
    int left = 0, right = m*n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int i = mid / n, j = mid % n;
        if (matrix[i][j] == target)
            return true;
        if (matrix[i][j] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {-10, -9, 0, 1},
        {8, 10, 11, 14},
        {20, 100, 777, 1000}
    };
    cout << searchMatrix(matrix, -10) << endl;
    return 0;
}
