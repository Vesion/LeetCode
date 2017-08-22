#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int search(string& t, string& s) {
    int m = t.size(), n = s.size();
    vector<int> prefix(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && t[i] != t[j]) j = prefix[j-1];
        if (t[i] == t[j]) ++j;
        prefix[i] = j;
    }

    int res = 0;
    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != t[j]) j = prefix[j-1];
        if (s[i] == t[j]) ++j;
        if (j == m) {
            ++res;
        }
    }
    return res;
}


int main() {
    int N; 
    cin >> N; 
    while (N--) {
        string t, s;
        cin >> t >> s;
        cout << search(t, s) << endl;
    }
    return 0;
}
