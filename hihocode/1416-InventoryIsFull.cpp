#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

const int MAX = 10005;
ll A[MAX], P[MAX], S[MAX];

struct Item {
    ll num, val;
    bool operator< (const Item& i) const { return val > i.val; }
};

Item items[MAX*2];

int main() {
    int N, M;    
    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> P[i];
    for (int i = 0; i < M; ++i) cin >> S[i];
    int r = 0;
    for (int i = 0; i < M; ++i) {
        ll a = A[i] / S[i], b = A[i] % S[i];
        if (a) items[r++] = {a, S[i] * P[i]};
        if (b) items[r++] = {1, b * P[i]};
    }
    sort(items, items+r);

    ll res = 0;
    for (int i = 0; i < r; ++i) {
        if (N >= items[i].num) {
            res += items[i].num * items[i].val;
            N -= items[i].num;
        } else {
            res += N * items[i].val;
            N = 0;
        }
        if (N == 0) break;
    }
    cout << res << endl;
    return 0;
}
