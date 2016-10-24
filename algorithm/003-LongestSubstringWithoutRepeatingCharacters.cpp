#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


// Sliding Window (hash table + two pointers)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> table(128, 0);
        int start = 0, end = 0, counter = 0, len = 0;
        while (end < (int)s.size()) {
            if (table[s[end++]]++ >= 1) counter++;
            while (counter > 0) {
                if (table[s[start++]]-- > 1) counter--;
            }
            len = max(len, end-start);
        }
        return len;
    }
};

int main() {
    Solution s;
    string s1 = "abba";
    cout<<s.lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
