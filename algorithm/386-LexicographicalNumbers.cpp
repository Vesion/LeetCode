#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : dfs
class Solution_1 {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, res);
        }
        return res;
    }

    void dfs(int cur, int n, vector<int>& res) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 0; i <= 9; ++i) {
            if (cur*10+i > n) return;
            dfs(cur*10+i, n, res);
        }
    }
};


// Solution 2 : generate, greedy
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int cur = 1;
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (cur*10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) cur /= 10;
                ++cur;
                while (cur%10 == 0) cur /= 10;
            } 
            res[i] = cur;
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
