#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int solve(string s) {
    int old = s.size();
    while (true) {
        bool f = false;
        string r;
        int i = 0, n = s.size();
        while (i < n) {
            char c = s[i];
            int count = 0;
            while (i < n && s[i] == c) ++count, ++i;
            if (count == 1) r += c;
            else f = true;
        }
        s = r;
        if (!f) break;
    }
    return old-s.size();
}

int main() {
    int T; cin >> T;
    char d[] = {'A', 'B', 'C'};
    while (T--) {
        string s; cin >> s;
        int res = 0;
        for (int i = 0; i <= (int)s.size(); ++i) {
            for (int j = 0; j < 3; ++j)
                res = max(res, solve(s.substr(0, i)+d[j]+s.substr(i)));
        }
        cout << res << endl;
    }
    return 0;
}
