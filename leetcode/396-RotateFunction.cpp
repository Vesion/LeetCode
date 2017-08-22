#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Pure math
// F[i] - F[i-1] = Sum - n*A[n-i]
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        int sum = 0, Fi = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            Fi += i*A[i];
        }
        int res = Fi;
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

