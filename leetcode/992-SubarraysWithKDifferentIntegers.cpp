#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar problems, longest subarray with at most k distinct elements:
// 340-LongestSubstringWithAtMostKDistinctCharacters
// 424-LongestRepeatingCharacterReplacement
// 992-SubarraysWithKDifferentIntegers

// It's not easy to solve exact_K problem, but it's much easier to solve at_most_K problem,
// see 340-LongestSubstringWithAtMostKDistinctCharacters,
// so the exact_K = at_most_K - at_most_(K-1)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atmost(A, K) - atmost(A, K-1);
    }

    int atmost(const vector<int>& A, int K) {
        int n = A.size();
        vector<int> m(n+1, 0);
        int res = 0, k = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (m[A[i]]++ == 0) ++k;
            while (k > K) {
                if (--m[A[j++]] == 0) --k;
            }
            res += (i-j+1);
        }
        return res;
    }
};

int main() {

}
