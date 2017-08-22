#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if (picture.empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> row(n, 0), col(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') { ++row[i]; ++col[j]; }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) ++res;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
