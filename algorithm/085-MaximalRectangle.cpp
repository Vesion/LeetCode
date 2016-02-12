#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Solution 1 : brute-force, O(n^3) time, O(n^2) space
// 暴力枚举，先用一个m*n的二位数组记录每个位置从左到自身的连续1的长度，即左向宽度，需要O(n^2)时间和O(n^2)空间
// 然后对每个点，先向上后向下遍历，找出左向宽度大于等于自己的那些行，加起来能得到以改点为右边所形成矩形的最大高度，宽度乘高度得到面积，记录最大面积，需要O(n^3)时间
// 复杂度过高，这里不实现


// Solution 2 : refer to 084-LargestRectangleInHistogram, O(n^2) time, O(n) space
// 联想第84题，虽然从一维变到了二维，但是思路相同，对二维点阵的每一行，都做一次largestRectangle操作，原理相同，时间O(n) * m = O(m*n)
int largestRectangle(vector<int> &height) {
    stack<int> hs;
    height.push_back(-1);
    int maxArea = 0;
    for (int i = 0; i < height.size(); ) {
        if (hs.empty() || height[i] > height[hs.top()]) {
            hs.push(i++);
        }
        else {
            int tmp = hs.top();
            hs.pop();
            maxArea = max(maxArea, height[tmp] * (hs.empty() ? i : i - hs.top() - 1));
        }
    }
    return maxArea;
}

int maximalRectangle_stack(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> height(n, 0); // here use 1D array to save space
    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            height[j] = (matrix[i][j] == '1' ? height[j]+1 : 0);
        }
        result = max(result, largestRectangle(height));
    }
    return result;
}


// Solution 3 : O(n^2) time, O(n) space, much faster
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
        cout << "L" << i << endl;
        for (auto k : L)
            cout << k << " ";
        cout << endl;
        for (int j = n-1; j >= 0; --j) {
            if (matrix[i][j] == '1') {
                R[j] = min(R[j], right); // the min index who is smaller than height
                result = max(result, H[j] * (R[j]-L[j]));
            } else {
                right = j;
            }
        }
        cout << "R" << i << endl;
        for (auto k : R)
            cout << k << " ";
        cout << endl;
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
    cout << maximalRectangle_stack(matrix) << endl;;
    return 0;
}
