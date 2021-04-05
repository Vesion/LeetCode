#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Pure math
// F[i] - F[i-1] = Sum - n*A[n-i]
class Solution {
public:
    using ll = long long;
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        ll n = A.size();
        ll sum = 0, Fi = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            Fi += i*A[i];
        }
        ll res = Fi;
        for (int i = 1; i < n; ++i) {
            Fi = Fi + sum - n*A[n-i];
            res = max(res, Fi);
        }
        return res;
    }
};


int main() {
    return 0;
}

