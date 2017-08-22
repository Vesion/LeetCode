#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

const int MAX = 100008;
int a[MAX];

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    ll res = 0;
    for (int i = 0; i < 32; ++i) {
        ll ones = 0;
        for (int j = 0; j < N; ++j) {
            if ((a[j]>>i) & 1) ++ones;
        }
        res += ones * (N-ones);
    }
    cout << res << endl;
    return 0;
}
