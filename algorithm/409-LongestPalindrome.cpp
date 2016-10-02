#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(256, 0);        
        for (auto& c : s) m[c-'\0']++;
        int result = 0;
        for (auto& i : m) result += i%2 ? (result%2 ? i-1 : i) : i;
        return result;
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("abccccdd");
    return 0;
}
