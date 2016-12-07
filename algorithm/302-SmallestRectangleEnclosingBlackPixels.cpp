#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty()) return 0;
        int m = image.size(), n = image[0].size();
        int top = binarySearch(image, x, m-1, n, false, true);
        int bottom = binarySearch(image, 0, x, n, false, false);
        int right = binarySearch(image, y, n-1, m, true, true);
        int left = binarySearch(image, 0, y, m, true, false);
        return (top-bottom+1) * (right-left+1);
    }

    int binarySearch(vector<vector<char>>& image, int start, int end, int max, bool horizontal, bool golower) {
        while (start <= end) {
            int mid = start + (end-start)/2;
            bool found = false;
            for (int i = 0; i < max; ++i) {
                if ((!horizontal && image[mid][i] == '1') || (horizontal && image[i][mid] == '1')) { found = true; break; }
            }
            if (found == golower) start = mid+1;
            else end = mid-1;
        }
        return golower ? end : start;
    }
};

int main() {
    Solution s;
    vector<vector<char>> i = {
        {'0', '0', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'},
    };
    cout << s.minArea(i, 2, 1) << endl;
    return 0;
}
