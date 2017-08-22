#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e4+5;
int a[MAXN];
int N;

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        int mina = INT_MAX;
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
            mina = min(mina, a[i]);
        }
        int res = INT_MAX;
        for (int base = mina-2; base <= mina; ++base) {
            int r = 0;
            for (int i = 0; i < N; ++i) {
                int d = a[i]-base;
                r += d/5; d %= 5;
                r += d/2; d %= 2;
                r += d;
            }
            res = min(res, r);
        }
        cout << res << endl;
    }
    return 0;
}
