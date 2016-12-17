#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Divide and conquer
// First count each character's occurrence times, then split string with those smaller than k and recursive
class Solution {
public:
    int longestSubstring(string s, int k) {
        return partition(s, k, 0, s.size());
    }

    int partition(string& s, int k, int start, int end) {
        int m[26] = {0};
        for (int i = start; i < end; ++i) m[s[i]-'a']++;

        int res = 0;
        int i = start;
        while (i < end) {
            if (m[s[i]-'a'] >= k) {
                int j = i;
                while (i < end && m[s[i]-'a'] >= k) ++i;
                if (j == start && i == end) return i-j; // recursion terminates
                res = max(res, partition(s, k, j, i));
            } else ++i;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("aaabbb", 3) <<endl;
    return 0;
}

