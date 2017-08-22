#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            while (i <= j && !isalnum(s[i])) ++i;
            while (i <= j && !isalnum(s[j])) --j;
            if (i <= j && tolower(s[i]) != tolower(s[j])) return false;
            ++i; --j;
        }
        return true;
    }
};


int main() {
    return 0;
}
