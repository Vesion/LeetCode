#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <set> 
using namespace std;

unordered_set<int> f({1, 2, 3, 5, 8, 13, 21, 34, 55, 89});

int main() {
    ios::sync_with_stdio(false);
    string s;    
    vector<bool> m(128, 0);
    set<string> res;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        fill_n(m.begin(), 128, 0);
        m[s[i]] = true;;
        int c = 1;
        for (int j = i; j < n; ++j) {
            if (!m[s[j]]) {
                m[s[j]] = true;
                ++c;
            }
            if (f.count(c)) res.insert(s.substr(i, j-i+1));
        }
    }
    for (string r : res) cout << r << endl;
    return 0;
}
