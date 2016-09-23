#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : naive dfs
class Solution_dfs {
public:
    int result = INT_MAX;
    void dfs(long long n, int steps) {
        if (n == 2) {
            result = min(result, steps);
            return;
        }
        if (n % 2) {
            dfs(n-1, steps+1);
            dfs(n+1, steps+1);
        }
        else dfs(n/2, steps+1);
    }

    int integerReplacement(int n) {
        if (n == 1) return 0;
        dfs(n, 1);
        return result;
    }
};


// Solution 2 : more deep analysis, iterative
class Solution {
public:
    int integerReplacement(int a) {
        int c = 0;
        long long n = a;
        while (n != 1) {
            if (n % 2) {
                if (n != 3 && (n+1) % 4 == 0) n++;
                else n--;
            }
            else n /= 2;
            ++c;
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.integerReplacement(INT_MAX) << endl;
    return 0;
}
