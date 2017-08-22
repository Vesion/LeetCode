#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int r[105];
int N, K;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        r[a%K]++;
    }
    int res = min(1, r[0]);
    if (K&1) for (int i = 1; i <= K/2; ++i) res += max(r[i], r[K-i]);
    else {
        for (int i = 1; i <= K/2-1; ++i) res += max(r[i], r[K-i]);
        res += min(1, r[K/2]);
    }
    cout << res << endl;
    return 0;
}
