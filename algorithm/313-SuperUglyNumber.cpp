#include <iostream>
#include <vector>
using namespace std;

// similar to 264-UglyNumberII, maintain a ascending sequence of primes' multiples, O(n*k) time
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 1);
        int m = primes.size();
        vector<int> f(m, 0);
        vector<int> nexts(m, 0);
        for (int i = 1; i < n; ++i) {
            res[i] = INT_MAX;
            for (int j = 0; j < m; ++j) {
                nexts[j] = res[f[j]]*primes[j];
                res[i] = min(nexts[j], res[i]);
            }
            for (int j = 0; j < m; ++j) {
                if (res[i] == nexts[j]) ++f[j];
            }
        }
        return res[n-1];
    }
};

int main() {
    return 0;
}
