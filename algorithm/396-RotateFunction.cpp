#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Math solution
// https://discuss.leetcode.com/topic/58459/java-o-n-solution-with-explanation
//
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        int F = 0;
        for (int i = 0; i < n; ++i) { // sum and F(0)
            sum += A[i];
            F += i * A[i];
        }

        int result = F;
        for (int i = 1; i < n; ++i) {
            F = F + sum - n * A[n-i]; // F(i) = F(i-1) + sum - n*Bk[0]
            result = max(result, F);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {4, 3, 2, 6} ;
    cout << s.maxRotateFunction(A) <<endl;
    return 0;
}
