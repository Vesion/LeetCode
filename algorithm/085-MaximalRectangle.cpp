#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time, O(n) space
// refer to others, very skillful
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();

    vector<int> H(n, 0); // height
    vector<int> L(n, 0); // left max
    vector<int> R(n, n); // right min

    int result = 0;

    for (int i = 0; i < m; ++i) {
        int left = 0, right = n;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                ++H[j];
                L[j] = max(L[j], left); // the max index who is smaller than height
            } else {
                left = j + 1;
                H[j] = 0; L[j] = 0; R[j] = n;
            }
        }
        for (int j = n-1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                R[j] = min(R[j], right); // the min index who is smaller than height
                result = max(result, H[j] * (R[j]-L[j]));
            } else {
                right = j;
            }
        }
    }

    return result;
}

int main() {
    vector<vector<char>> matrix = {
        {'0', '1', '1', '0', '1', '0'},
        {'1', '1', '0', '1', '0', '0'},
        {'0', '1', '1', '1', '0', '0'},
        {'1', '1', '1', '1', '0', '0'},
        {'1', '1', '1', '1', '1', '0'},
        {'0', '0', '0', '0', '0', '0'},
    };
    cout << maximalRectangle(matrix) << endl;;
    return 0;
}
