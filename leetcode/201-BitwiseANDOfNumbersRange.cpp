#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : consider from lowest bit to highest bit, judge each bit whether can be 0 or not
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long res = m;
        while (res) {
            long long low = res & -res;
            if (res + low <= n) res &= (res-1);
            else break;
        }
        return res;
    }
};


// Solution 2 : set right most bits to 0 if m != n
class Solution_2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int trans = 0;
        while(m != n) {
            ++trans;
            m >>= 1;
            n >>= 1;
        }
        return m << trans;
    }
};


// Solution 3 : find the left most common bits (similar to solution 2, but faster)
class Solution_3 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int mask = INT_MAX;
        while ((m & mask) != (n & mask)) mask <<= 1;
        return n & mask;
    }
};


int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(0, INT_MAX) << endl;;
    return 0;
}

