#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

using ll = long long;

const int MAXN = 100005;
int N;
const int MAXA = 1<<20;
int hfirst[MAXA], hsecond[MAXA];

int main() {
    int T; cin >> T;
    while (T--) {
        memset(hfirst, 0, sizeof hfirst);
        memset(hsecond, 0, sizeof hsecond);
        cin >> N;
        int x;
        while (N--) {
            scanf("%d", &x);
            for (int i = x; i > 0; i = (i-1)&x) { // think about it
                if (x > hfirst[i]) {
                    hsecond[i] = hfirst[i];
                    hfirst[i] = x;
                } else if (x > hsecond[i]) {
                    hsecond[i] = x;
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < MAXA; ++i) {
            res = max(res, (ll)hfirst[i]*hsecond[i]*i);
        }
        cout << res << endl;
    }
    return 0;
}
