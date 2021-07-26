#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// This is a hard counting problem.
// https://discuss.leetcode.com/topic/64624/concise-easy-to-understand-java-5ms-solution-with-explaination
//
// Count nodes in a denary tree
class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        --k;
        using ll = long long;
        while (k > 0) {
            int count = 0;
            for (ll first = res, last = res+1; first <= n; first *= 10, last *= 10)
                count += min(ll(n+1), last) - first;
            if (count <= k) {
                k -= count;
                res += 1;
            } else {
                --k;
                res *= 10;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.findKthNumber(INT_MAX, 100) << endl;
    return 0;
}
