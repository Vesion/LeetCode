#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial backtracking
class Solution_1 {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 0;
        for (int i = 1; i <= 9; ++i) res += dfs(i, 1, n, 1<<i);
        return res+1;
    }
    
    int dfs(int cur, int len, int n, int used) {
        if (len > n) return 0;
        int res = 1;
        for (int i = 0; i <= 9; ++i) 
            if (!(used & (1<<i))) res += dfs(cur, len+1, n, used|(1<<i));
        return res;
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
