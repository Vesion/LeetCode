#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Restate the problem:
//      Given an integer n, it can be wrote in k-base form s, if s is 1111.. (all 1s), k is good base, we need to find the smallest good base k, (k >= 2)
//
// First thing come in mind:
//      1. the largest good base k is n-1, and s is 11
//      2. so the naive brute force solution is try each k from 2 to n-1, the first good base is our result
//      3. how to improve?
//
// Some observations:
//      1. if good base k, n = k^d + k^(d-1) + k^(d-2) + .. + k^1 + k^0
//      2. so now the problem is converted into finding the largest d, d is the len(s)-1
//      3. what about try each d from the largest to smallest
//         the largest d is 62, because n <= 10^18 < 2^62, the smallest d is 2
//      4. for each d (i.e. for each s 111... whose length is d+1)
//         we need to check whether there exists k, k^d + d^(d-1) + ... + 1 = n
//      5. how to check? bianry search, the lower bound of k is 2, upper bound is the d-th root of n, i.e. pow(n, 1/d)

// Solution 1 : binary search
class Solution_1 {
public:
    using ull = unsigned long long;
    string smallestGoodBase(string n) {
        ull N = (ull)stoll(n);
        ull x = 1;
        for (int d = 63; d >= 1; --d) {
            if ((x<<d) <= N) {
                ull res = bs(N, d);
                if (res) return to_string(res);
            }
        }
        return to_string(N-1);
    }
    
    ull bs(ull N, int d) {
        ull left = 2, right = pow(N, 1.0/d);
        while (left <= right) {
            ull mid = left + (right-left)/2;
            ull sum = 1, k = mid;
            // check if mid^0 + ... + mid^d ?= N
            for (int i = 1; i <= d; ++i) {
                sum += k;
                k *= mid;
            }
            if (sum == N) return mid;
            if (sum < N) left = mid+1;
            else right = mid-1;
        }
        return 0;
    }
};


// Further thinkings:
//      1. Do we need to iterate from 62? 
//         No, the largest d is logN/log2, i.e. k = 2
//      2. For each d, do we have a faster solution to check whether there exists a valid k, that 1 + ... + k^d = n
//         Yes, we only need to check the d-th root of n

// Solution 2 : math
class Solution {
public:
    using ull = unsigned long long;
    string smallestGoodBase(string n) {
        ull N = (ull)stoll(n);
        for (int d = log(N)/log(2)+1; d >= 2; --d) {
            int k = pow(N, 1.0/d);
            ull sum = 1, cur = 1;
            for (int i = 1; i <= d; ++i) sum += (cur *= k);
            if (sum == N) return to_string(k);
        }
        return to_string(N-1);
    } 
};


int main() {
    Solution_1 s1;
    cout << s1.smallestGoodBase("15") << endl;
    Solution s;
    cout << s.smallestGoodBase("4681") << endl;
    return 0;
}
