#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s; 
    vector<int> m(128, 0);
    m['h'] = 2;
    m['i'] = m['o'] = 1;
    int i = 0, j = 0, c = 4, n = s.size();
    int res = n+1;
    while (j < n) {
        if (m[s[j++]]-- > 0) --c;
        while (c == 0) {
            if (m['h'] == 0 && m['i'] == 0 && m['o'] == 0) res = min(res, j-i);
            if (m[s[i++]]++ == 0) ++c;
        }
    }
    if (res > n) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
