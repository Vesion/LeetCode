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
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if (desiredTotal <= maxChoosableInteger) return true;
        int used = 0;
        vector<int> m(1<<maxChoosableInteger, -1);
        return win(desiredTotal, maxChoosableInteger, used, m);
    }

    bool win(int desiredTotal, int maxChoosableInteger, int& used, vector<int>& m) {
        if (desiredTotal <= 0) return false;
        if (m[used] != -1) return m[used];
        bool res = false;
        for (int i = 0; i < maxChoosableInteger; ++i) { // try all possible numbers
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


int main() {
    Solution s;
    cout << s.canIWin(11, 25) << endl;
    return 0;
}

