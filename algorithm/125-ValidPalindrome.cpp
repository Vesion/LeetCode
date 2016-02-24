#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    if (s.empty()) return true;
    for (int i = 0, j = s.size()-1; i <= j; ++i, --j) {
        while (!isalnum(s[i]) && i < s.size()) ++i;
        while (!isalnum(s[j]) && j >= 0) --j;
        if (i > j) break;
        if (tolower(s[i]) != tolower(s[j])) return false;
    }
    return true;
}

int main() {
    cout << isPalindrome(" ") << endl;
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome("race a car") << endl;
    return 0;
}
