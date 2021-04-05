#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

// Math : Canton Expression
// k = an*(n-1)! + an-1*(n-2)! + ... + ai*(i-1)! + ... + a2*1! + a1*0!
class Solution {
public:
    string getPermutation(int n, int k) {
        string dict(n, '0');
        iota(dict.begin(), dict.end(), '1');
        --k;  // to be zero-based
        string res(n, '0');
        for (int i = 0; i < n; ++i) {
            int f = factorial(n-1-i);
            int j = k / f;
            k %= f;
            res[i] = dict[j];
            dict.erase(dict.begin() + j);
        }
        return res;
    }

    // return x!
    int factorial(int x) {
        int res = 1;
        for (int i = 1; i <= x; ++i) res *= i;
        return res;
    }
};


int main() {
    return 0;
}
