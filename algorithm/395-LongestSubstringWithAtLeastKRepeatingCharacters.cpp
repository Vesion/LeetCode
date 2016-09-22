#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// divide and conquer
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, k, 0, s.size());
    }

    int longestSubstring(string& s, int k, int start, int end) {
        int c[26] = {0};
        for (int i = start; i < end; ++i) c[s[i]-'a']++;

        int result = 0;
        for (int i = start; i < end; ) {
            while (i < end && c[s[i]-'a'] < k) ++i;
            if (i == end) break;
            int j = i;
            while (j < end && c[s[j]-'a'] >= k) ++j;
            if (i == start && j == end) return end-start;
            result = max(result, longestSubstring(s, k, i, j));
            i = j;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("ababacb", 3) << endl;
    return 0;
}
