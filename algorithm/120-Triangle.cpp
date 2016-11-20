#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int n = triangle.size();
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j < (int)triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main() {
    Solution s;
    return 0;
}

