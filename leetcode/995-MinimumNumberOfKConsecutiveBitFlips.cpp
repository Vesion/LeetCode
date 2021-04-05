#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Greedy, flip from left most one by one
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/238609/JavaC%2B%2BPython-One-Pass-and-O(1)-Space

class Solution0 {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int res = 0;
        // if A[i] need to be flipped (consequence of all former flips)
        bool flipped = 0;
        // is_flipped[i] = if flipped A[i...i+K-1]
        vector<bool> is_flipped(n, false);

        // check if need to flip A[i...i+K-1]
        for (int i = 0; i < n; ++i) {
            // update flipped with all flips happen between i-K and i-1
            if (i >= K) flipped = flipped ^ is_flipped[i-K];

            // if A[i] is 1 but it should be flipped to 0, we need to flip it to 1 again
            // if A[i] is 0 and it was not flipped before, we need to flip it to 1
            if ((A[i] == 1 && flipped) || (A[i] == 0 && !flipped)) {
                // cannot flip i because length of A[i..n-1] is < K
                if (i + K > n) return -1;
                is_flipped[i] = true;
                flipped = !flipped;
                ++res;
            }
        }
        return res;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        // number of flips in a sliding window
        int flips = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i-K] > 1) {  // when A[i-K] move out of window
                --flips;
                A[i-K] -= 2;
            }
            if ((flips%2 == 0 && A[i] == 0) || (flips%2 == 1 && A[i] == 1)) {
                if (i+K > n) return -1;
                A[i] += 2;  // mark A[i] was flipped
                ++flips;
                ++res;
            }
        }
        return res;
    }
};

int main() {

}
