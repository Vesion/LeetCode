#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : maintain a sliding window:
//      (length of substring - number of times of the maximum occurring character in the substring) <= k
// it's very slow because we calculate real max_element every time
class Solution_1 {
public:
    int characterReplacement(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0;
        int res = 0;
        while (j < (int)s.size()) {
            m[s[j++]]++;
            if (j-i-*max_element(m.begin(), m.end()) > k) m[s[i++]]--;
            res = max(res, j-i);
        }
        return res;
    }
};


// Solution 2 : no need to calculate real-time max_element, much faster
// https://discuss.leetcode.com/topic/63494/java-12-lines-o-n-sliding-window-solution-with-explanation/2
//
// window doesn't shrink, just extend or shift
// we do not need the accurate max count of the current window; we only care if the max count exceeds the historical max count; and that can only happen because of the new char.
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0, c = 0;
        while (j < (int)s.size()) {
            c = max(c, ++m[s[j++]]);
            if (j-i-c > k) m[s[i++]]--;
        }
        return s.size()-i;
    }
};


int main() {
    return 0;
}
