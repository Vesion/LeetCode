#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

int N, M;
unordered_map<string, string> parent;
string c1, c2;

bool find() {
    unordered_set<string> s;
    s.insert(c1);
    while (parent.count(c1)) {
        c1 = parent[c1];
        s.insert(c1);
    }

    if (s.count(c2)) return true;
    while (parent.count(c2)) {
        c2 = parent[c2];
        if (s.count(c2)) return true;
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string p, c;
        cin >> p >> c;
        parent[c] = p;
    }

    cin >> M;
    while (M--) {
        cin >> c1 >> c2;
        if (find()) cout << c2 << endl;
        else cout << -1 << endl;
    }
    return 0;
}

