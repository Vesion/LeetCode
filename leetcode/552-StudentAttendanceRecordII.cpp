#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, O(n) time, O(n) space,
//     can be O(1) space, just for meaningful code
class Solution {
public:
    using ll = long long;
    static constexpr ll kMod = 1e9 + 7;

    int checkRecord(int n) {
        if (n == 0) return 0;
        if (n == 1) return 3;
        if (n == 2) return 8;

        std::vector<ll> a(n);  // number of valid records ending with 'A'
        std::vector<ll> p(n);  // number of valid records ending with 'P'
        std::vector<ll> l(n);  // number of valid records ending with 'L'
        std::vector<ll> nap(n);  // number of valid records ending with 'P', but no 'A'
        std::vector<ll> nal(n);  // number of valid records ending with 'L', but no 'A'
        a[0] = 1, p[0] = 1, l[0] = 1, nap[0] = 1, nal[0] = 1;
        a[1] = 2, p[1] = 3, l[1] = 3, nap[1] = 2, nal[1] = 2;

        for (int i = 2; i < n; ++i) {
            a[i] = (nap[i-1] + nal[i-1]) % kMod;  // (noA).PA, (noA).LA
            p[i] = (a[i-1] + p[i-1] + l[i-1]) % kMod;  // .AP, .PP, .LP
            l[i] = (a[i-1] + p[i-1] + a[i-2] + p[i-2]) % kMod;  // .AL, .PL, .ALL, .PLL
            nap[i] = (nap[i-1] + nal[i-1]) % kMod;  // (noA).PP, (noA).LP
            nal[i] = (nap[i-1] + nap[i-2]) % kMod;  // (noA).PL, (noA).PLL
        }

        return (a[n-1] + p[n-1] + l[n-1]) % kMod;
    }
};

// can be optimized by fast matrix power, to O(logn)

int main() {
    Solution s;
    cout << s.checkRecord(2) << endl;
    return 0;
}
