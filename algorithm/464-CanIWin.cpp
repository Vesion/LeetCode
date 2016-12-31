#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <deque> 
using namespace std;

// Similar to 294-FlipGameII


// Solution 1 : top-down dp
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        int used = 0;
        vector<int> m(1<<maxChoosableInteger, -1);
        return win(desiredTotal, maxChoosableInteger, used, m);
    }

    bool win(int desiredTotal, int maxChoosableInteger, int& used, vector<int>& m) {
        if (desiredTotal <= 0) return false;
        if (m[used] != -1) return m[used];
        bool res = false;
        for (int i = 0; i < maxChoosableInteger; ++i) {
            int mask = 1 << i;
            if (!(used & mask)) {
                used |= mask;
                res = !win(desiredTotal-i-1, maxChoosableInteger, used, m);
                used ^= mask;
                if (res) break;
            }
        }
        m[used] = res;
        return res;
    }
};


// Solution 2 : bottom-up dp
class Solution_2 {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (desiredTotal > maxChoosableInteger*(maxChoosableInteger+1)/2) return false;

        int n = 1 << maxChoosableInteger;
        vector<bool> dp(n, false);

        for (int mask = 0; mask < n; ++mask) {
            int total = 0;
            for (int i = 0; i < maxChoosableInteger; ++i) {
                if ((mask & (1<<i)) == 0) total += i+1;
            }
            if (total >= desiredTotal) {
                dp[mask] = false;
                continue;
            }

            for (int i = 0; i < maxChoosableInteger; ++i) {
                if (mask & (1<<i)) {
                    if (dp[mask ^ (1<<i)] == 0) {
                        dp[mask] = true;;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    cout << s.canIWin(11, 25) << endl;
    return 0;
}

