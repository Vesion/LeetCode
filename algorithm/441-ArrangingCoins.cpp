#include <iostream>
#include <algorithm>
#include <cmath> 
#include <vector>
#include <string>
using namespace std;

// Solution 1 : count, O(logn)
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while (n >= i) {
            n -= i;
            i++;
        }
        return i-1;
    }
};


// Solution 2 : bianry search, O(logn)
class Solution_2 {
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


// Solution 3 : solve square equation, O(1)
class Solution_3 {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + 8.0*n) - 1) / 2;
    }
};


int main() {
    Solution s;
    return 0;
}
