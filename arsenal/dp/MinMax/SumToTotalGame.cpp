#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/can-i-win/
// Given N numbers [1, N], two players take turns picking one and add it to a running total, the player who first causes the running total to reach or exceed target wins.

// top-down + memo
class Solution {
public:
    bool canIWin(int n, int target) {
        if (n*(n+1)/2 < target) return false;
        if (target <= n) return true;
        int used = 0;
        vector<int> memo(1<<n, -1); // memo[used] record used states
        return win(n, target, used, memo);
    }

    bool win(int n, int target, int& used, vector<int>& memo) {
        if (target <= 0) return false;
        if (memo[used] != -1) return memo[used];
        bool res = false;
        for (int i = 0; i < n; ++i) {
            if (used & (1 << i)) continue;
            used |= (1 << i);
            res = !win(n, target-i-1, used, memo);
            used ^= (1 << i);
            if (res) break;
        }
        memo[used] = res;
        return res;
    }
};


int main() {
    return 0;
}
