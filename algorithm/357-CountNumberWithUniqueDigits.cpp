#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Solution 1 : dfs + backtracking
class Solution {
public:
    int upper, visited, res;

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        upper = pow(10, n);
        res = 0;
        visited = 0;
        for (int i = 1; i <= 9; ++i)
            dfs(i, i);
        return res + 1;
    }

    void dfs(int cur, int digit) {
        if (cur >= upper) return;
        ++res;
        visited |= (1 << digit);
        for (int i = 0; i <= 9; ++i) {
            if (!((visited>>i)&1)) dfs(cur*10+i, i);
        }
        visited ^= (1 << digit);
    }
};


// Solution 2 : math
// Let f(k) = count of numbers with unique digits with length equals k.
//      f(1) = 10
//      f(2) = 9 * 9
//      ......
//      f(k) = 9 * 9 * 8 * ... (9-k+2) (The first factor is 9 because a number cannot start with 0).
class Solution_2 {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10;
        for (int i = 2; i <= n; ++i) {
            int k = 9;
            for (int j = 9; j >= 9-i+2; --j) k *= j;
            res += k;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) <<endl;
    return 0;
}

