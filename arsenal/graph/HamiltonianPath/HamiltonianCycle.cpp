#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://hihocoder.com/discuss/question/2192/

int edge[13];
int node[1<<13];
int n, m;
int res;

void dfs(int cur, int visited) {
    if (visited == (1<<n)-1) {
        if (edge[cur]&1) ++res;
        return;
    }
    int rest = ~visited & edge[cur];
    while (rest) {
        int pos = rest & -rest;
        dfs(node[pos], visited|pos);
        rest -= pos;
    }
}

int main() {
    for (int i = 0; i < 12; ++i) node[1<<i] = i+1; 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        edge[a] |= (1<<(b-1));
    }
    dfs(1, 1);
    cout << res << endl;
    return 0;
}


