#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }

    bool check(const string& a, const string& b) {
        int n = a.size();
        int i = 0, j = n-1;
        while (i < j && a[i] == b[j]) ++i, --j;
        return i >= j || ispalindrome(a, i, j) || ispalindrome(b, i, j);
    }

    bool ispalindrome(const string& s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
};

int main() {

}
