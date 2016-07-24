#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Solution 1 : back-tracking
class Solution_1 {
public:
    int cnt = 0;
    bool m[10] = {false};
    int N;

    void dfs(int c, int i) {
        if (c >= N) return;
        if (m[i]) return;
        ++cnt;
        m[i] = true;
        for (int k = 0; k <= 9; ++k)
            dfs(c*10+k, k);
        m[i] = false;
    }

    int countNumbersWithUniqueDigits(int n) {
        N = pow(10, n);
        for (int i = 1; i <= 9; ++i)
            dfs(i, i);
        return cnt+1;
    }
};


// dp
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n <= 0) return 1;
        int result = 10;
        for (int i = 2; i <= n; ++i) {
            int k = 9;
            for (int j = 9; j >= 9-i+2; --j)
                k *= j;
            result += k;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(0) << endl;
    return 0;
}
