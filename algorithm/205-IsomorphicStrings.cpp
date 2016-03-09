#include <iostream>
#include <string>
using namespace std;


// Solution 1 : use a mapping table, and a used table
bool isIsomorphic_1(string s, string t) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    int m[256] = {0};
    bool used[256] = {true};
    for (int i = 0; i < n; ++i) {
        int sk = s[i] + 1;
        int tk = t[i] + 1;
        if (!m[sk]) {
            if (used[tk]) return false;
            m[sk] = tk;
            used[tk] = true;
        } else {
            if (m[sk] != tk) return false;
        }
    }
    return true;
}

// Solution 2 : use two mapping tables
bool isIsomorphic_2(string s, string t) {
    if (s.size() != t.size()) return false;
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; i < s.size(); ++i) {
        int sk = s[i], tk = t[i];
        if (m1[sk] != m2[tk]) return false;
        m1[sk] = i+1;
        m2[tk] = i+1;
    }
    return true;
}

int main() {
    cout << isIsomorphic_1("egg", "eaa") << endl;
    cout << isIsomorphic_1("egg", "eaa") << endl;
    return 0;
}
