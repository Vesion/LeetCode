#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// min-max, two players follow different rules
class Solution {
public:
    int n;
    // dp[t][m][c] = the result of t's turn (to identify mouse or cat) with position (m, c)
    vector<vector<vector<int>>> dp;

    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        dp = vector<vector<vector<int>>>(n*2, vector<vector<int>>(n, vector<int>(n, -1)));
        return win(graph, 0, 1, 2);
    }

    int win(vector<vector<int>>& graph, int t, int m, int c) {
        if (t == n*2) return 0;  // why?
        if (m == 0) return 1;
        if (c == m) return 2;
        if (dp[t][m][c] != -1) return dp[t][m][c];

        if (t%2 == 0) {
            bool draw = false;
            for (int nm : graph[m]) {
                int r = win(graph, t+1, nm, c);
                if (r == 1) return dp[t][m][c] = 1;
                if (r == 0) draw = true;
            }
            if (draw) return dp[t][m][c] = 0;
            else return dp[t][m][c] = 2;
        } else {
            bool draw = false;
            for (int nc : graph[c]) {
                if (nc == 0) continue;  // cat cannot go to the hole
                int r = win(graph, t+1, m, nc);
                if (r == 2) return dp[t][m][c] = 2;
                if (r == 0) draw = true;
            }
            if (draw) return dp[t][m][c] = 0;
            else return dp[t][m][c] = 1;
        }
    }
};

int main() {

}
