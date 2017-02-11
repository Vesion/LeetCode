#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <deque> 
using namespace std;

// dfs + memo, similar to 294-FlipGameII
class Solution {
public:
    bool canIWin(int n, int target) {
        if (n*(n+1)/2 < target) return false;
        if (target <= n) return true;
        int used = 0;
        vector<int> memo(1<<n, -1);
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
    Solution s;
    cout << s.canIWin(11, 25) << endl;
    return 0;
}

