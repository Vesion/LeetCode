#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The Minimum Spanning Tree - Kruskal Algorithm
//
// http://poj.org/problem?id=1251 

const int MAX = 128;

int root[MAX], ranks[MAX];

void makeset() {
    for (int i = 0; i < MAX; ++i) {
        root[i] = i;
        ranks[i] = 0;
    }
}

int findroot(int x) {
    if (root[x] != x)
        root[x] = findroot(root[x]);
    return root[x];
}

void unionset(int x, int y) {
    int rx = root[x], ry = root[y];
    if (rx == ry) return;
    if (ranks[rx] > ranks[ry])
        root[ry] = rx;
    else {
        if (ranks[rx] == ranks[ry])
            ++ranks[ry];
        root[rx] = ry;
    }
}


struct Edge {
    int start, end, weight;
    bool operator<(const Edge& e) const { return weight < e.weight; }
} edges[MAX * MAX / 2];

int N;

int kruskal(int c) {
    int sum = 0;
    makeset();
    for (int i = 0; i < c; ++i) {
        if (findroot(edges[i].start) != findroot(edges[i].end)) {
            unionset(edges[i].start, edges[i].end);
            sum += edges[i].weight;
        }
    }
    return sum;
}

int main() {
    while (cin >> N && N != 0) {
        char x, y;
        int m, w;
        int c = 0;
        for (int i = 0; i < N-1; ++i) {
            cin >> x >> m;
            for (int j = 0; j < m; ++j) {
                cin >> y >> w;
                edges[c].start = x - 'A';
                edges[c].end = y - 'A';
                edges[c].weight = w;
                ++c;
            }
        }
        sort(edges, edges+c);
        cout << kruskal(c) << endl;
    }    
    return 0;
}

