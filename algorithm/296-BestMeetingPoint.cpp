#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Median gives the shortest distance.
// But sort to find median is trivial, here we calculate totoal distance directly in linear time.
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> xs, ys;
        int res = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) xs.push_back(i);
        int left = 0, right = xs.size()-1;
        while (left < right) res += xs[right--] - xs[left++];

        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (grid[i][j] == 1) ys.push_back(j);
        left = 0, right = ys.size()-1;
        while (left < right) res += ys[right--] - ys[left++];

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> g = {
        {1,0,0,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0},
    };
    cout << s.minTotalDistance(g) << endl;
    return 0;
}
