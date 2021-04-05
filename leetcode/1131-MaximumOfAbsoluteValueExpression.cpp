#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// math
// https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/340075/c%2B%2B-beats-100-(both-time-and-memory)-with-algorithm-and-image
class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0, n = x.size(), smallest, cur;
        for (int p : {1, -1}) {
            for (int q : {1, -1}) {
                smallest = p * x[0] + q * y[0] + 0;
                for (int i = 1; i < n; ++i) {
                    cur = p * x[i] + q * y[i] + i;
                    res = max(res, cur - smallest);
                    smallest = min(smallest, cur);
                }
            }
        }
        return res;
    }
};

int main() {

}
