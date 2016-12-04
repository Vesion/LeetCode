#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;


// Solution 1 : DP, O(n*sqrt(n))
class Solution_1 {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; j*j <= i; ++j) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


// Solution 2 : BFS, O(n)
// Consider a perfect square number as a node, extend all valid nodes level by level.
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<bool> visited(n+1, false);
        for (int i = 1; i*i <= n; ++i) {
            squares.push_back(i*i);
            visited[i*i] = true;
        }
        if (squares.back() == n) return 1;

        queue<int> q;
        for (int s : squares) q.push(s);

        int level = 1;
        while (!q.empty()) {
            ++level;
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                int node = q.front(); q.pop();
                for (int s : squares) {
                    if (node+s == n) return level;
                    if ((node+s < n) && !visited[node+s]) {
                        q.push(node+s);
                        visited[node+s] = true;
                    }
                    else if (node+s > n) break;
                }
            }
        }
        return 0; // never
    }
};


// Solution 3 : mathematical, Number Theory, very tricky, O(sqrt(n)), 4ms
// based on Lagrange's Four Square theorem (https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)
class Solution_3 {
public:
    int numSquares(int n) {
        if (isSquare(n)) return 1;
        while ((n&3) == 0) n >>= 2;
        if ((n&7) == 7) return 4;
        int x = int(sqrt(n));
        for (int i = 1; i <= x; ++i) {
            if (isSquare(n - i*i)) return 2;
        }
        return 3;
    }

    bool isSquare(int x)  {
        float i = sqrt(x);
        return floor(i) == i;
    }
};

int main() {
    return 0;
}

