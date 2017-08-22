#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k;
    cin >> s;

    vector<int> m(128, 0);
    for (char& c : s) ++m[c];
    string res(k, 0);
    int j = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
        --m[s[i]];
        while (j > 0 && s[i] < res[j-1] && n-i+j > k) --j;
        if (j < k) res[j++] = s[i];
    }
    cout << res << endl;

    return 0;
}
