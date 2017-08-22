#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n; cin >> n; 
    vector<pair<string,int>> s(n);
    for (int i = 0; i < n; ++i) {
        string w; cin >> w;
        int j = 0;
        while (j < (int)w.size()) {
            if (isdigit(w[j])) break;
            ++j;
        }
        s[i] = {w.substr(0, j), stoi(w.substr(j))};
    }
    sort(s.begin(), s.end());
    for (auto& p : s) cout << p.first << to_string(p.second) << endl;
    return 0;
}
