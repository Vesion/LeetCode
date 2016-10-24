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
        vector<int> table(128, 0);
        int start = 0, end = 0, len = 0;
        while (end < (int)s.size()) {
            table[s[end++]]++;
            if (end-start-*max_element(table.begin(), table.end()) > k)
                table[s[start++]]--;
            len = max(len, end-start);
        }
        return len;
    }
};

int main() {
    Solution s;
    return 0;
}
