#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Sliding Window (hash table + two pointers)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int m[128]; fill_n(m, 128, -1);
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (m[s[j]] != -1) {
                while (i < m[s[j]]+1) m[s[i++]] = -1;
            }
            res = max(res, j-i+1);
            m[s[j]] = j;
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
