#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left <= right) {
            while (left <= right && !isalnum(s[left])) ++left;
            while (left <= right && !isalnum(s[right])) --right;
            if (left <= right && tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("  ") <<endl;
    return 0;
}

