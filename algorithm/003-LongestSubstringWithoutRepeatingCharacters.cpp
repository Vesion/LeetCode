#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


// hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = {0};
        fill(m, m+256, -1);
        int start = 0;
        int result = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            int x = s[i] - '\0';
            if (m[x] >= start) start = m[x]+1;
            result = max(result, i-start+1);
            m[x] = i;
        }
        return result;
    }
};

int main() {
    Solution s;
    string s1 = "abba";
    cout<<s.lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
