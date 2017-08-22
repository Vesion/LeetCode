#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int solve() {
    string s; int k;
    cin >> s; cin >> k;
    int n = s.size();
    int res = 0;
    if (k*2 <= n) {
        for (int i = 0; i < k; ++i) if (s[i] != s[n-k+i]) ++res;
        return res;
    }
    int len = n-k;
    for (int i = 0; i < len; ++i) {
        vector<int> count(4, 0);
        for (int j = i; j < n; j += len) {
            if (s[j] == 'A') ++count[0];
            else if (s[j] == 'T') ++count[1];
            else if (s[j] == 'C') ++count[2];
            else ++count[3];
        }
        int maxc = 0;
        for (int& c : count) {
            maxc = max(maxc, c);
            res += c;
        }
        res -= maxc;
    }
    return res;
}

int main() {
    int T; cin >> T; 
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}
