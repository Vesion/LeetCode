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
            dp[i] = INT_MAX;
            for (int j = 1; j <= i/j; ++j) {
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
        queue<int> q;
        vector<bool> visited(n+1, false);
        for (int i = 1; i <= n/i; ++i) {
            squares.push_back(i*i);
            q.push(i*i);
            visited[i*i] = true;
        }
        if (squares.back() == n) return 1;
        
        int res = 1;
        while (!q.empty()) {
            ++res;
            int len = q.size();
            while (len--) {
                int t = q.front(); q.pop();
                for (int& s : squares) {
                    int next = t+s;
                    if (next == n) return res; // return result before enqueue to speed up
                    if (next > n) break;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return 0;
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

