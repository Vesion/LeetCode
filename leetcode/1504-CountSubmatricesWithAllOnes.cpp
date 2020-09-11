#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// DP, O(m*n*n)
class Solution0 {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        // dp[j][l] = number of rectangles ending at (i, j) with width l
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            vector<vector<int>> ndp(n, vector<int>(n+1, 0));
            int l = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) ++l;
                else l = 0;
                for (int d = 1; d <= l; ++d) {
                    ndp[j][d] = 1 + dp[j][d];
                    res += ndp[j][d];
                }
            }
            dp.swap(ndp);
        }
        return res;
    }
};

// Monotonically increasing stack, O(m*n)
// 084-LargestRectangleInHistogram.cpp
// 085-MaximalRectangle.cpp
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> hs(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) hs[j]++;
                else hs[j] = 0;
            }
            res += num_rects(hs);
        }
        return res;
    }

    int num_rects(const vector<int>& hs) {
        stack<pair<int,int>> st;  // index, sum
        int res = 0;
        for (int i = 0; i < hs.size(); ++i) {
            while (!st.empty() && hs[st.top().first] >= hs[i]) st.pop();
            int sum = 0;
            if (st.empty()) {
                sum = hs[i] * (i+1);
            } else {
                sum = hs[i] * (i - st.top().first) + st.top().second;
            }
            st.push({i, sum});
            res += sum;
        }
        return res;
    }
};

int main() {
    vector<int> h({2,2,2});
    Solution s;
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}
