#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sliding window
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> m(128, 0);
        int i = 0, j = 0, c = 0;
        int res = 0;
        while (j < (int)s.size()) {
            if (m[s[j++]]++ == 0) ++c;
            while (c > 2)
                if (m[s[i++]]-- == 1) --c;
            res = max(res, j-i);
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLongestSubstringTwoDistinct("eceba") << endl;
    return 0;
}
