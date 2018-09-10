#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

// Dijkstra, min-heap, O((V+E)logV)
// Practically, it runs not so faster than the O(V^2) version.

const int MAXN = 1e3+5;
vector<pair<int,int>> g[MAXN];
int dist[MAXN];
int N, M, S, T;

bool cmp(const int& i, const int& j) { // we need a min-heap
    return dist[i] > dist[j];
}

void dijkstra_heap(int s) {
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    dist[s] = 0;
    vector<int> heap(N); iota(heap.begin(), heap.end(), 1);
    make_heap(heap.begin(), heap.end(), cmp);
    while (!heap.empty()) {
        pop_heap(heap.begin(), heap.end(), cmp); // extract the nearest vertex from heap
        int i = heap.back(); heap.pop_back();
        for (auto& p : g[i]) { // relax edges of it
            int j = p.first, l = p.second;
            dist[j] = min(dist[j], dist[i]+l);
        }
        make_heap(heap.begin(), heap.end(), cmp); // re-heapify, actually it's O(n) here
    }
}


int main() {
    cin >> N >> M >> S >> T;
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    dijkstra_heap(S);
    cout << dist[T] << endl;
    return 0;
}

