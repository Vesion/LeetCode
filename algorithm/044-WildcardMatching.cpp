#include <iostream>
#include <string>
using namespace std;

// Solution 1 : two pointers
// The most skillful, most concise, most fast solution!
// https://leetcode.com/discuss/10133/linear-runtime-and-constant-space-solution
bool isMatchC(const char* s, const char* p) {
    const char* star = NULL;
    const char* ss = s;
    while (*s) {
        // advancing both pointers when (both characters match) or ('?' found in pattern)
        // note that *p will not advance beyond its length 
        if ((*p == '?') || (*p == *s)) { ++s; ++p; continue; }

        // * found in pattern, track index of *, only advancing pattern pointer
        if (*p == '*') { star = p++; ss = s; continue; }

        // current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        // only advancing pattern pointer
        if (star) { p = star + 1; s = ++ss; continue; }

        // current pattern pointer is not star, last patter pointer was not *
        // characters do not match
        return false;
    }
    while (*p == '*') ++p; // check for remaining '*'s in pattern
    return !*p; // pattern must be iterated over
}

bool isMatch(string s, string p) {
    return isMatchC(s.c_str(), p.c_str());
}

int main() {
    cout << isMatch("aabcd", "a*c?") << endl;
    return 0;
}
