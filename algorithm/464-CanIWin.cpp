#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <deque> 
using namespace std;

// backtracking + memo, similar to 294-FlipGameII
class Solution {
public:
    bool canIWin(int n, int target) {
        if (n*(1+n)/2 < target) return false;
        if (target <= n) return true;
        vector<int> m(1<<n, -1);
        return win(n, target, 0, m);
    }
    
    bool win(int n, int target, int used, vector<int>& m) {
        if (target <= 0) return false;
        if (m[used] != -1) return m[used];
        bool res = false;
        for (int i = 0; i < n; ++i) {
            if (!(used & (1<<i))) {
                res |= !win(n, target-i-1, used|(1<<i), m);
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
