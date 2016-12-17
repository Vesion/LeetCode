#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Pure math
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        int sum = 0, F = 0; // sum and F(0)
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            F += i * A[i];
        }

        int res = F;
        for (int i = 1; i < n; ++i) {
            F = F + sum - n*A[n-i]; // F(i) = F(i-1) + sum - n*Bk[0]
            res = max(res, F);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

