#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Sliding window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> m(128, 0);
        int i = 0, j = 0;
        int count = 0;
        int res = 0;
        while (j < (int)s.size()) {
            if (m[s[j++]]++ == 0) ++count;
            while (count > k) {
                res = max(res, j-i-1);
                if (m[s[i++]]-- == 1) --count;
            }
        }
        res = max(res, j-i);
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
