#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// This is a hard counting problem.
//
// The core algorithm is to count the number of numbers that prefix which 'result'
//      A number prefix with 'result' is like:
//          [result, result+1)
//          [result*10, (result+1)*10)
//          [result*100, (result+1)*100)
//          ...
//      If the number of numbers prefix with 'result' is smaller than k, we incease 'result' by 1, and repeat last step
//      Else, we need more detailed counting. We should start with 'result' * 10
//
// https://discuss.leetcode.com/topic/64462/c-python-0ms-o-log-n-2-time-o-1-space-super-easy-solution-with-detailed-explanations


class Solution {
public:
    int findKthNumber(int n, int k) {
        int result = 1;    
        --k;
        while (k > 0) {
            int count = 0;
            for (long long first = result, last = first+1; first <= n; first *= 10, last *= 10) {
                count += (min(n+1LL, last) - first);
            }
            if (k >= count) {
                k -= count;
                ++result;
            } else {
                --k;
                result *= 10;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.findKthNumber(1000000, 1) << endl;
    return 0;
}
