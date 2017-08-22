#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 26;

int root[MAX], ranks[MAX];

void makeset() {
    for (int i = 0; i < MAX; ++i) {
        root[i] = i;
        ranks[i] = 0;
    }
}

int findroot(int x) {
    if (x != root[x])
        root[x] = findroot(root[x]);
    return root[x];
}

void unionset(int x, int y) {
    int rx = findroot(x), ry = findroot(y);
    if (rx == ry) return;
    if (ranks[rx] > ranks[ry])
        root[ry] = rx;
    else {
        if (ranks[rx] == ranks[ry]) ++ranks[ry];
        root[rx] = ry;
    }
}

int ind[MAX], outd[MAX];
int g[MAX][MAX];
bool has[MAX];

// Directed Grapth
bool hasEulerPath() {
    int s = 0, e = 0;
    bool flag = true;
    for (int i = 0; i < MAX; ++i) {
        if (has[i] && outd[i] != ind[i]) {
            if (outd[i] == ind[i]+1) s++;
            else if (ind[i] == outd[i]+1) e++;
            else flag = false;
        }
    }
    return flag && ((s == 1 && e == 1) || (s == 0 && e == 0));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(ind, 0, sizeof ind);
        memset(outd, 0, sizeof outd);
        memset(g, 0, sizeof g);
        memset(has, false, sizeof has);
        makeset();

        int n;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            int start = s[0]-'a', end = s[s.size()-1]-'a';
            has[start] = has[end] = true;
            outd[start]++;
            ind[end]++;
            unionset(start, end);
        }
        
        int c = 0;
        for (int i = 0; i < MAX; ++i)
            if (has[i] && findroot(i) == i) ++c;
        if (c > 1) {
            cout << "The door cannot be opened." << endl;
            continue;
        }

        if (hasEulerPath())
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
    }
    return 0;
}
