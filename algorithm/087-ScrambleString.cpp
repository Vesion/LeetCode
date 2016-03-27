#include <iostream>
#include <string>
using namespace std;


// Solution 1 : recursive, 4ms
//      "@@######"   or  "@@######"
//      "@@######"       "######@@"
bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;
    int n = s1.size();
    int count[26] = {0};

    for (int i = 0; i < n; ++i) count[s1[i]-'a']--, count[s2[i]-'a']++;
    for (auto c : count) if (c) return false;

    for (int i = 1; i <= n-1; ++i) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
        if (isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))) return true;
    }
    return false;
}

int main() {
    cout << isScramble("rgtae", "great") << endl;
    return 0;
}
