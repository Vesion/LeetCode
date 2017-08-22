#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 105;
char s[MAXN];

int anagram(int start, int n, vector<int> m, int len) {
    if (start >= n) return 0;
    int i = start, j = start, c = len;
    int res = 0;
    while (j < n) {
        if (m[s[j++]]-- > 0) --c; 
        if (c == 0) ++res;
        if (j-i == len && m[s[i++]]++ >= 0) ++c;
    }
    return res;
}

int main() {
    int T; cin >> T;
    while (T--) {
        scanf("%s", s);
        int n = strlen(s);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> m(128, 0);
            int c = 0;
            for (int j = i; j < n; ++j) {
                m[s[j]]++; ++c;
                res += anagram(i+1, n, m, c);
            }
        }
        cout << res << endl;
    }
    return 0;
}
