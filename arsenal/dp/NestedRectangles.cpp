#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem:
//      Given n rectanges with the format (w, h) w <= h, rectangle r1 can be included (nested) by r2 if and only if
//      (r1.w < r2.w && r1.h < r2.h) || (r1.w < r2.h && r1.h < r2.w)
//      find out the largest number of nested rectangles
// 
// Solution:
//      Convert it into a DAG, each rectange is a node, if r1 can be included by r2, then there exists an edge starts from r1 points to r2
//      then we need to find the longest path in the DAG


// memorization
int dfs(vector<pair<int, int>>& rs, vector<vector<bool>>& inc, vector<int>& dp, int cur) {
    if (dp[cur]) return dp[cur];
    dp[cur] = 1;
    for (int i = 0; i < (int)rs.size(); ++i) {
        if (inc[i][cur])
            dp[cur] = max(dp[cur], dfs(rs, inc, dp, i)+1);
    }
    return dp[cur];
}

int nestedRectangles(vector<pair<int, int>>& rs) {
    int n = rs.size();
    vector<vector<bool>> inc(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((rs[i].first < rs[j].first && rs[i].second < rs[j].second) 
                || (rs[i].first < rs[j].second && rs[i].second < rs[j].first)) 
                inc[i][j] = true;
        }
    }
    int result = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        result = max(result, dfs(rs, inc, dp, i));
    }
    return result;
}


int main() {
    vector<pair<int, int>> rs = {
        {1, 2},
        {1, 3},
        {5, 6},
        {100, 110},
        {7,8},
        {7, 9}
    };    
    cout << nestedRectangles(rs) <<endl;
    return 0;
}
