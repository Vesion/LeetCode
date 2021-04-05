#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar problems, longest subarray with at most k distinct elements:
// 340-LongestSubstringWithAtMostKDistinctCharacters
// 424-LongestRepeatingCharacterReplacement
// 992-SubarraysWithKDifferentIntegers

// Solution 1 : maintain a sliding window:
//      (length of substring - number of times of the maximum occurring character in the substring) <= k
// it's very slow because we calculate real max_element every time
class Solution_1 {
public:
    int characterReplacement(string s, int k) {
        int c[26] = {0};
        int res = 0;
        int i = 0, j = 0;
        for (; i < s.size(); ++i) {
            ++c[s[i]-'A'];
            if (i-j+1 - *max_element(begin(c), end(c)) > k) --c[s[j++]-'A'];
            res = max(res, i-j+1);
        }
        return res;
    }
};


// Solution 2 : no need to calculate real-time max_element, much faster
// window doesn't shrink, just extend or shift
// we do not need the accurate max count of the current window;
// we only care if the max count exceeds the historical max count;
// and that can only happen because of the new char.
class Solution {
public:
    int characterReplacement(string s, int k) {
        int c[26] = {0};
        int res = 0;
        int i = 0, j = 0, max_c = 0;
        for (; i < s.size(); ++i) {
            // maintain a global max_c, instead of evaluating the maximum c for every i
            max_c = max(max_c, ++c[s[i]-'A']);
            if (i-j+1 - max_c > k) --c[s[j++]-'A'];
            res = max(res, i-j+1);
        }
        return res;
    }
};


int main() {
    return 0;
}
