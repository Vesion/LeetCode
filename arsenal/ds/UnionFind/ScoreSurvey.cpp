#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// https://hihocoder.com/problemset/problem/1515

const int MAXN = 100005;
int root[MAXN];
int dist[MAXN];
int N, M, Q;

// find root with path compression, be careful with the distance
int findRoot(int i) {
    if (root[i] != i) {
        int t = root[i];
        root[i] = findRoot(root[i]);
        dist[i] += dist[t];
    }
    return root[i];
}

void unionSet(int i, int j, int d) {
    int ri = findRoot(i), rj = findRoot(j);
    if (ri != rj) {
        root[rj] = ri;
        dist[rj] = dist[i]+d-dist[j]; // union distance
    }
}

int main() {
    cin >> N >> M >> Q; 
    for (int i = 1; i <= N; ++i) root[i] = i;

    for (int i = 0; i < M; ++i) {
        int a, b, d; cin >> a >> b >> d;
        unionSet(a, b, d);
    }

    for (int i = 0; i < Q; ++i) {
        int a, b; cin >> a >> b;
        int ra = findRoot(a), rb = findRoot(b);
        if (ra != rb) cout << -1 << endl;
        else cout << dist[b]-dist[a] << endl;
    }
    return 0;
}

