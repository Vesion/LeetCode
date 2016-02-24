#include <iostream>
#include <vector>
using namespace std;

// Solution 0 : dfs-backtracking, TLE of course
// just for understanding
void dfs(vector<vector<int>>& triangle, int &total, int row, int col, int sum) {
    if (col < 0 || col >= triangle[row].size()) return; // illegal branch
    if (row == triangle.size()) { // terminate
        total = min(total, sum);
        return;
    }
    if (sum >= total) return; // prune
    dfs(triangle, total, row+1, col, sum+triangle[row][col]);
    dfs(triangle, total, row+1, col+1, sum+triangle[row][col]);
}

int minimumTotal_dfs(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    int total = INT_MAX;
    dfs(triangle, total, 0, 0, 0);
    return total;
}


// Solution 1 : dp + scrolling array
int minimumTotal_dp(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    int rows = triangle.size();
    vector<int> dp(1);
    dp[0] = triangle[0][0];
    for (int i = 1; i < rows; ++i) {
        dp.resize(triangle[i].size());
        for (int j = dp.size()-1; j >= 0; --j) {
            if (j == dp.size()-1) dp[j] = dp[j-1] + triangle[i][j];
            else if (j == 0) dp[j] += triangle[i][j];
            else dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
        }
    }
    return *min_element(dp.begin(), dp.end());
}

// Solution 2 : dp, modify triangle, O(1) space
int minimumTotal_dpO1(vector<vector<int>>& triangle) {
    if (triangle.empty()) return 0;
    int m = triangle.size();
    for (int i = m-2; i >= 0; --i)
        for (int j = 0; j < triangle[i].size(); ++j)
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
    return triangle[0][0];
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 0, 8, 3}};
    cout << minimumTotal_dfs(triangle) << endl;
    cout << minimumTotal_dp(triangle) << endl;
    cout << minimumTotal_dpO1(triangle) << endl;
    return 0;
}
