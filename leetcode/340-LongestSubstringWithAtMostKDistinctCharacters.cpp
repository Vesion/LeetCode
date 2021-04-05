#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar problems, longest subarray with at most k distinct elements:
// 340-LongestSubstringWithAtMostKDistinctCharacters
// 424-LongestRepeatingCharacterReplacement
// 992-SubarraysWithKDifferentIntegers

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(256, 0);
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (m[s[i]]++ == 0) --k;
            while (j <= i && k < 0) {
                if (--m[s[j++]] == 0) ++k;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};


int main() {
    return 0;
}
