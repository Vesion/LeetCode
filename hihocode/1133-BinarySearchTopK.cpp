#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1e6+5;
int a[MAXN];
int N, K;

int partition(int s, int e) {
    int pivot = a[s];
    int l = s+1, r = e;
    while (l <= r) {
        while (l <= r && a[l] < pivot) ++l;
        while (l <= r && a[r] > pivot) --r;
        if (l <= r) swap(a[l++], a[r--]);
    }
    swap(a[r], a[s]);
    return r;
}

int topk() {
    int l = 0, r = N-1;
    while (l <= r) {
        int p = partition(l, r);
        if (p+1 == K) return a[p];
        if (p+1 < K) l = p+1;
        else r = p-1;
    }
    return -1;
}
