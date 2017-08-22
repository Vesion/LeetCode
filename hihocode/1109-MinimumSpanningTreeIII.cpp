#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
using namespace std;

const int MAXN = 1e5+5;
vector<pair<int,int>> g[MAXN];
int dist[MAXN], has[MAXN];
int id[MAXN]; // track position of each node in heap, for re-heapify after updating dist
int N, M;

#define left(i) (i*2+1)
#define right(i) (i*2+2)
#define parent(i) ((i-1)/2)

bool cmp(const int& i, const int& j) {
    return dist[i] > dist[j];
}

void shift_down(vector<int>& heap, int n, int i) {
    int max_i = i;
    if (left(i) < n && cmp(heap[max_i], heap[left(i)])) max_i = left(i);
    if (right(i) < n && cmp(heap[max_i], heap[right(i)])) max_i = right(i);
    if (max_i == i) return;
    swap(heap[i], heap[max_i]);
    swap(id[heap[i]], id[heap[max_i]]);
    shift_down(heap, n, max_i);
}

void sift_up(vector<int>& heap, int i) {
    int min_i = i;
    if (i > 0 && cmp(heap[parent(i)], heap[i])) min_i = parent(i);
    if (min_i == i) return;
    swap(heap[i], heap[min_i]);
    swap(id[heap[i]], id[heap[min_i]]);
    sift_up(heap, min_i);
}

void build_heap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n/2; i >= 0; --i) shift_down(heap, n, i);
}

void extract_top(vector<int>& heap) {
    int n = heap.size();
    swap(heap[0], heap[n-1]);
    swap(id[heap[0]], id[heap[n-1]]);
    shift_down(heap, n-1, 0);
}

int prim_heap() {
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    dist[1] = 0;
    int res = 0;
    vector<int> heap(N); iota(heap.begin(), heap.end(), 1);
    for (int i = 1; i <= N; ++i) id[i] = i-1;
    build_heap(heap);
    for (int k = 1; k <= N; ++k) {
        extract_top(heap);
        int i = heap.back(); heap.pop_back();
        id[i] = -1;
        res += dist[i];
        for (auto& p : g[i]) {
            int j = p.first, l = p.second;
            if (dist[j] > l) {
                dist[j] = l;
                if (id[j] != -1) sift_up(heap, id[j]);
            }
        }
    }
    return res;
}

int main() {
    cin >> N >> M; 
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    cout << prim_heap() << endl;
    return 0;
}
