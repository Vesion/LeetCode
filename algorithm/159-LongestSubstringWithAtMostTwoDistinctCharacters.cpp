#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sliding window
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<int> m(128, 0);
        int left = 0, right = 0;
        int c = 0;
        int res = 0;
        while (right < (int)s.size()) {
            if (m[s[right++]]++ == 0) ++c;
            while (c > 2) {
                res = max(res, right-left-1);
                if (m[s[left++]]-- == 1) --c;
            }
        }
        res = max(res, right-left);
        return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    return 0;
}
