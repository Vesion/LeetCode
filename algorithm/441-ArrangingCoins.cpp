#include <iostream>
#include <algorithm>
#include <cmath> 
#include <vector>
#include <string>
using namespace std;

// Solution 1 : bianry search, O(logn)
class Solution {
public:
    int arrangeCoins(int n) {
        long long m = 2LL*n;    
        long long left = 0, right = m/2;
        while (left <= right) {
            long long mid = left + (right-left)/2;
            long long t = (1+mid)*mid;
            if (t == m) return mid;
            if (t < m) left = mid+1;
            else right = mid-1;
        }
        return right;
    }
};


// Solution 2 : solve square equation, O(1)
class Solution_2 {
public:
    int arrangeCoins(int n) {
        return sqrt(2 * (long)n + 1 / 4.0) - 1 / 2.0;
    }
};

int main() {
    Solution s;
    return 0;
}
