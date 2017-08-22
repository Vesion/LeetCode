#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int z[3];
vector<int> c(128, 0);

bool vanish() {
    int d[3];
    d[0] = abs(c['R'] - c['B']);
    d[1] = abs(c['R'] - c['Y']);
    d[2] = abs(c['B'] - c['Y']);
    sort(d, d+3);
    return d[0] == z[0] && d[1] == z[1] && d[2] == z[2];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> z[0] >> z[1] >> z[2];
    sort(z, z+3);
    string s;
    cin >> s;
    int i = 0, j = 0;
    int res = 0;
    while (j < (int)s.size()) {
        c[s[j++]]++;
        res = max(res, j-i);
        if (vanish()) {
            i = j;
            fill(c.begin(), c.end(), 0);
        }
    }
    cout << res << endl;
    return 0;
}
