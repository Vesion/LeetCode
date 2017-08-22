#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = long long;

int main() {
    vector<ll> table(40);
    for (int i = 0; i < 40; ++i) table[i] = 1LL << i;
    ll N; cin >> N;
    int res = 0;
    while (N > 0) {
        ++res;
        auto right = lower_bound(table.begin(), table.end(), N);
        if (*right == N) break;
        auto left = right-1;
        if (N-*left < *right-N) N -= *left;
        else N = *right-N;
    }
    cout << res << endl;
    return 0;
}
