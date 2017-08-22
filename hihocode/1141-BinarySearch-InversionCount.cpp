#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 1e5+5;
int a[MAXN];
int b[MAXN];
int N;

ll mergesort(int l, int r) { if (l+1 >= r) return 0;
    int mid = l+(r-l)/2;
    ll res = mergesort(l, mid)+mergesort(mid, r);
    int j = mid, k = 0;
    for (int i = l; i < mid; ++i) {
        while (j < r && a[j] < a[i]) b[k++] = a[j++];
        b[k++] = a[i];
        res += j-mid;
    }
    move(b, b+k, a+l);
    return res;
}


int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    cout << mergesort(0, N) << endl;
    return 0;
}
