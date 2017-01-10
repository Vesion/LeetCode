#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial backtracking
class Solution_1 {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 0, used = 0;
        for (int i = 1; i <= 9; ++i) dfs(i, 0, n, used, res);
        return res+1;
    }
    
    void dfs(int cur, int len, int n, int& used, int& res) {
        if (len == n) return;
        ++res;
        used |= (1 << cur);
        for (int i = 0; i <= 9; ++i) {
            if (!(used & (1<<i))) dfs(i, len+1, n, used, res);
        }
        used ^= (1 << cur);
    }
};


// Solution 2 : math
// Let  f(k) = count of numbers with unique digits with length equals k.
//      f(1) = 10
//      f(2) = 9*9 
//      f(i) = 9*9*...*(11-i)   [The first factor is 9 because a number cannot start with 0]
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        int res = 10;
        for (int i = 2; i <= n; ++i) {
            int c = 9;
            for (int j = 9; j >= 11-i; --j) c *= j;
            res += c;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(3) <<endl;
    return 0;
}
