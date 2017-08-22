#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// sliding window

int main() {
    int K;
    string s;
    cin >> K;
    cin >> s;

    vector<int> m(128, 0);
    for (char& c : s) ++m[c];

    int res = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (m[c] == 0) continue;
        int i = 0, k = K, len = 0;
        for (int j = 0; j < (int)s.size(); ++j) {
            if (s[j] == c) {
                if (len < m[c]) ++len;
            } else {
                if (k > 0 && len < m[c]) { --k; ++len; }
                else if (k == 0) {
                    for (; i < j; ++i) {
                        if (s[i] == c) --len;
                        else { k = 1; --len; ++i; break; }
                    }
                }
            }
            res = max(res, len);
        }
    }
    cout << res << endl;

    return 0;
}
