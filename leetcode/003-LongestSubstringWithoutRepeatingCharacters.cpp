#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Sliding Window (hash table + two pointers)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c[256] = {};
        int i = 0, j = 0;
        int res = 0;
        for (; i < s.size(); ++i) {
            ++c[s[i]];
            while (c[s[i]] > 1) --c[s[j++]];
            res = max(res, i-j+1);
        }
        return res;
    }
};

int main() {
    Solution s;
    string s1 = "abba";
    cout<<s.lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
