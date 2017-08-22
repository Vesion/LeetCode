#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define long long long
#define mod 1000000007ll
#define M 500500
#define N 13001000
const int T = 314159;

string a, b;
long p[M], x[M], s[N];

void pre() {
    p[0] = 1;
    for (int i = 1; i < M; ++i)
        p[i] = (2 * p[i - 1]) % mod;
}

void read() {
    cin >> a >> b;

    for (int i = 0; i < (int) a.length(); ++i)
        x[a.length() - 1 - i] = a[i] == '1' ? 1 : 0;

    for (int i = 0; i < (int) b.length(); ++i)
        s[b.length() - 1 - i + M] = b[i] == '1' ? 1 : 0;

    for (int i = 1; i < N; ++i)
        s[i] += s[i - 1];
}

long sum(int l, int r) {
    return s[r + M] - s[l + M];
}

void kill() {
    long ans = 0;
    for (int i = 0; i < M; ++i)
        if (x[i] == 0)
            ans = (ans + p[i] * sum(i - T - 1, i)) % mod;
        else
            ans = (ans + p[i] * (T + 1 - sum(i - T - 1, i))) % mod;
    cout << ans << "\n";
}


int main() {
    pre();
    read();
    kill();
    return 0;
}
