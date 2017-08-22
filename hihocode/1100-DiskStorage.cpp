#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int r[100008];


int main() {
    ios::sync_with_stdio(false);
    int N, M, H, R;
    cin >> N >> M >> H >> R;
    for (int i = 0; i < N; ++i) cin >> r[i];

    sort(r, r+N);
    int s = 0;
    int res = min(H, N);
    for (int i = 0; i < N; ++i) {
        if (i > 0 && r[i]-r[i-1] > M)
            s = 0;
        if (r[i] > R+s) {
            res = min(i, H);
            break;
        }
        ++s;
    }
    cout << res << endl;
    return 0;
}
