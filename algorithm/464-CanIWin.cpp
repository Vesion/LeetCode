#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <deque> 
using namespace std;

// Solution 1 : top-down dp, dfs + memo
class Solution {
    vector<int> cache;
    int state;
    int maxInt;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        maxInt = maxChoosableInteger;
        state = 0;
        cache = vector<int> (1<<maxChoosableInteger, -1);
        return helper(desiredTotal);
    }

    bool helper(int desiredTotal) {
        if (desiredTotal <= 0) return false;
        if (cache[state] != -1) return cache[state];
        int mask = 1;
        for (int i=0; i<maxInt; ++i) {
            if (!(state & mask)) {
                state |= mask;
                if (!helper(desiredTotal-i-1)) {
                    state &= ~mask;
                    cache[state] = 1;

                    return true;
                }
                state &= ~mask;
            }
            mask <<= 1;
        }
        cache[state] = 0;
        return false;
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

