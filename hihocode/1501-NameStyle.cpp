#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool isupper(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        int n = s.size();
        string r;
        bool f = 0;
        for (char& c : s) if (c == '_') f = 1;
        if (f) {
            vector<string> w;
            int i = 0, j = 0;
            while (j < n) {
                if (s[j] == '_') {
                    w.push_back(s.substr(i, j-i));
                    i = j+1;
                }
                ++j;
            }
            w.push_back(s.substr(i, j-i));
            for (string& t:w) {
                t[0] = toupper(t[0]);
                r += t;
            }
            r[0] = tolower(r[0]);
        } else {
            vector<string> w;
            int i = 0, j = 0;
            while (j < n) {
                if (isupper(s[j])) {
                    w.push_back(s.substr(i, j-i));
                    i = j;
                }
                ++j;
            }
            w.push_back(s.substr(i, j-i));
            for (string& t : w) {
                t[0] = tolower(t[0]);
                r += t + '_';
            }
            r.pop_back();
        }
        cout << r <<endl;
    }
    return 0;
}
