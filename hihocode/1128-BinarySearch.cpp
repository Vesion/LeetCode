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

int bs() {
    int l = 0, r = N-1;
    while (l <= r) {
        int mid = l+(r-l)/2;
        if (a[mid] == K) return mid+1;
        else if (a[mid] < K) l = mid+1;
        else r = mid-1;
    }
    return -1;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a+N);
    cout << bs() << endl;
    return 0;
}
