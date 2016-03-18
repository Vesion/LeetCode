#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// the famous 'Perfect Square' problem

bool isSquare(int x)  {
    float i = sqrt(x);
    return floor(i) == i;
}

// Solution 0 : brute-force dp, O(n^2) time, TLE!
int numSquares_tle(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (isSquare(i)) dp[i] = 1;
        else for (int j = 1; j < i; ++j) dp[i] = min(dp[i], dp[j]+dp[i-j]);
    }
    return dp[n];
}

// Solution 1 : dp, O(n*sqrt(n)) time, 436ms
// dp[i] is the least number of perfect square numbers which sum to i; for i, it must be the sum of some number and a perfect square number
int numSquares_dp(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j*j <= i; ++j) // j*j is a perfect square number, so we find the minimum dp[i-j*j]
            dp[i] = min(dp[i], dp[i - j*j]+1);
    }
    return dp[n];
}


// Solution 2 : bfs, O(2n) time, 80ms
int numSquares_bfs(int n) {
    vector<int> squares; // store all perfect square numbers smaller than or equal to n
    vector<int> count(n); // same with the dp array above, here we use it to flag a number where has been visited
    for (int i = 1; i*i <= n; ++i) {
        squares.push_back(i*i);
        count[i*i-1] = 1;
    }
    if (squares.back() == n) return 1; // n is exactly a perfect square number, so return 1

    queue<int> q;
    for (auto & i : squares) q.push(i); // the first level of nodes are all perfect quare numbers

    int result = 1; // level
    while (!q.empty()) {
        ++result;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            int node = q.front();
            for (auto & j : squares) { // j must be a square number
                if (node + j == n) return result; // so the current node + a square number = n, its level is result
                if ((node + j < n) && count[node+j-1] == 0) { // if the number node+j-1 hasn't been visited, flag it
                    count[node+j-1] = result;
                    q.push(node+j);
                }
                else if (node +j > n) break; // out of bounder
            }
            q.pop();
        }
    }
    return 0; // never
}

// Solution 3 : mathematical, Number Theory, very tricky, O(sqrt(n)), 4ms
// based on Lagrange's Four Square theorem (https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)
int numSquares_math(int n) {
    if (isSquare(n)) return 1;
    while ((n&3) == 0) n >>= 2;
    if ((n&7) == 7) return 4;
    int x = int(sqrt(n));
    for (int i = 1; i <= x; ++i) {
        if (isSquare(n - i*i)) return 2;
    }
    return 3;
}

int main() {
    cout << numSquares_tle(7691) << endl;
    cout << numSquares_dp(7691) << endl;
    cout << numSquares_bfs(7691) << endl;
    cout << numSquares_math(7691) << endl;
    return 0;
}
