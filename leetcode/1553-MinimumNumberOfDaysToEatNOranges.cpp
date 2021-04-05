#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// bfs
class Solution {
public:
    int minDays(int n) {
        queue<int> q;
        q.push(n);
        unordered_set<int> m;
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int t = q.front(); q.pop();
                if (t == 0) return res;
                if (!m.count(t-1)) {
                    m.insert(t-1); q.push(t-1);
                }
                if (t%3 == 0 && !m.count(t/3)) {
                    m.insert(t/3); q.push(t/3);
                }
                if (t%2 == 0 && !m.count(t/2)) {
                    m.insert(t/2); q.push(t/2);
                }
            }
            ++res;
        }
        return res;
    }
};

// straight forward top-down dp, stack overflow
class Solution {
public:
    unordered_map<int,int> dp;
    int minDays(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];
        int res = INT_MAX;
        if (n%3 == 0) res = min(res, minDays(n/3)+1);
        if (n%2 == 0) res = min(res, minDays(n/2)+1);
        res = min(res, minDays(n-1)+1);
        return dp[n] = res;
    }
};

// greedy + dp
class Solution {
public:
    unordered_map<int,int> dp;
    int minDays(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp.count(n)) return dp[n];
        int res = 1 + min(n%3+minDays(n/3), n%2+minDays(n/2));
        return dp[n] = res;
    }
};

int main() {

}