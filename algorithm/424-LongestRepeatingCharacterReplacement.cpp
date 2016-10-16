#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// A very good problem to learn Sliding Window Problem

// We need to maintain a sliding window:
//      (length of substring - number of times of the maximum occurring character in the substring) <= k
//
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, m[26] = {};
        while (j < (int)s.size()) {
            m[s[j++]-'A']++; // extend
            if (j-i - *max_element(m, m+26) > k)
                m[s[i++]-'A']--; // shrink
        }
        return j - i;
    }
};

int main() {
    Solution s;
    return 0;
}
