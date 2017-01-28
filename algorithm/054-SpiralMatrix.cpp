#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        vector<int> res;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[top][j]);
            if (++top > bottom) break;

            for (int i = top; i <= bottom; ++i) res.push_back(matrix[i][right]);
            if (left > --right) break;

            for (int j = right; j >= left; --j) res.push_back(matrix[bottom][j]);
            if (top > --bottom) break;

            for (int i = bottom; i >= top; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};


int main() {
    return 0;
}
