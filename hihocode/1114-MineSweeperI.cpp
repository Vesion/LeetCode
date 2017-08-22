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
int m0[MAXN], m1[MAXN];
int r0[MAXN], r1[MAXN];
int N;

bool sweep(int x0, int* m) {
    m[0] = x0;
    m[1] = a[0]-m[0]; if (m[1] < 0 || m[1] > 1) return false;
    for (int i = 2; i < N; ++i) {
        m[i] = a[i-1] - (m[i-2]+m[i-1]);
        if (m[i] < 0 || m[i] > 1) return false;
    }
    if (m[N-1]+m[N-2] != a[N-1]) return false;
    return true;
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> a[i];

        bool f0 = sweep(0, m0), f1 = sweep(1, m1);
        int c0 = 0, c1 = 0;
        for (int i = 0; i < N; ++i) {
            if (f0 && f1) {
                if (m0[i] && m1[i]) r1[c1++] = i+1;
                else if (!m0[i] && !m1[i]) r0[c0++] = i+1;
            } else if (f0) {
                if (m0[i]) r1[c1++] = i+1;
                else if (!m0[i]) r0[c0++] = i+1;
            } else {
                if (m1[i]) r1[c1++] = i+1;
                else if (!m1[i]) r0[c0++] = i+1;
            }
        }
        cout << c1 << " "; for (int i = 0; i < c1; ++i) cout << r1[i] << " "; cout << endl;
        cout << c0 << " "; for (int i = 0; i < c0; ++i) cout << r0[i] << " "; cout << endl;
    }
    return 0;
}
