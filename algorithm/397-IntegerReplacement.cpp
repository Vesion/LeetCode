#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : trivial dfs
class Solution_1 {
public:
    int integerReplacement(int n) {
        int res = INT_MAX;
        dfs(n, 0, res);
        return res;
    }

    void dfs(long long n, int step, int& res) {
        if (n == 1) {
            res = min(res, step);
            return;
        }
        if (n&1) {
            dfs(n+1, step+1, res);
            dfs(n-1, step+1, res);
        } else
            dfs(n/2, step+1, res);
    }
};


// Solution 2 : bitmap
// eliminate 1 as soon as possible, so when:
//      n is even, n /= 2 (right shift)
//      n is odd, if the last two significant bits are
//          01, n -= 1
//          10, n += 1
class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long long ln = n;
        while (ln != 1) {
            if ((ln&1) == 0) ln >>= 1;
            else {
                if (ln == 3 || ((ln>>1)&1) == 0) --ln;
                else ++ln;
            }
            ++res;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.integerReplacement(2) <<endl;
    return 0;
}

