#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1e6+5;
struct Edge {
    int a, b, l;
    bool operator<(const Edge& other) const { return l < other.l; }
};
Edge edges[MAXN];
int root[MAXN], c;
int removed[MAXN];
int N, M, K;

int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
}

int kruskal() {
    for (int i = 1; i <= N; ++i) root[i] = i;
    c = 0;
    int res = 0;
    for (int i = 0; i < M; ++i) {
        int ra = findRoot(edges[i].a), rb = findRoot(edges[i].b);
        if (ra != rb) {
            res += edges[i].l;
            root[rb] = ra;
        }
    }
    return res;
}


int main() {
    cin >> N >> M >> K;    
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].a >> edges[i].b >> edges[i].l;
    }
    sort(edges, edges+M);
    return 0;
}
