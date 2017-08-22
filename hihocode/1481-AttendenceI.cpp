#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool check(string& s) {
    int a = 0, l = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'L') {
            ++l;
        } else {
            l = 0;
            if (s[i] == 'A') ++a;
        }
        if (a > 1 || l == 3) return false;
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        if (check(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
