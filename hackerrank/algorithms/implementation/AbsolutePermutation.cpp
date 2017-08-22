#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
int N, K;

bool solve() {
    if (N == 1 || K == 0) {
        for (int i = 1; i <= N; ++i) a[i] = i;
        return true;
    }
    if (N%(2*K) != 0) return false;
    for (int i = 1; i <= N; ++i) a[i] = i;
    for (int i = 1; i <= N; i += 2*K) {
        for (int j = i; j < i+K; ++j) swap(a[j], a[j+K]);
    }
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N >> K;
        bool r = solve();
        if (r) for (int i = 1; i <= N; ++i) cout << a[i] << " ";
        else cout << -1;
        cout << endl;
    }
    return 0;
}
