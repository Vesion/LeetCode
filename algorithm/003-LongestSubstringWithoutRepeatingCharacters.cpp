#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


// Sliding Window (hash table + two pointers)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int res = 0;
        for (int i = 0, j = 0; j < (int)s.size(); ) {
            if (m[s[j++]]++) 
                while (m[s[i++]]-- == 1); // find the repeating one
            res = max(res, j-i);
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
