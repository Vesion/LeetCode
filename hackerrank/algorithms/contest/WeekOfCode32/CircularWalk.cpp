#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <queue> 
using namespace std;
using ll = long long;

const int MAXN = 1e7+5;
int r[MAXN];
int v[MAXN];
int N, S, T;
int G, Seed, P;

int solve() {
    if (S == T) return 0;
    queue<int> q;
    q.push(S); v[S] = 1;
    int s = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            int t = q.front(); q.pop();
            if (abs(t-T) <= r[t] || N-abs(t-T) <= r[t])
                return s+1;

            for (int i = t-r[t]; i < t; ++i) {
                int j = (i+N)%N;
                if (!v[j]) {
                    q.push(j); v[j] = 1;
                } else break;
            }
            for (int i = t+r[t]; i > t; --i) {
                int j = (i+N)%N;
                if (!v[j]) {
                    q.push(j); v[j] = 1;
                } else break;
            }
        }
        ++s;
    }
    return -1;
}

int main() {
    cin >> N >> S >> T; 
    cin >> r[0] >> G >> Seed >> P;
    for (int i = 1; i < N; ++i) {
        r[i] = (r[i-1]*G + Seed)%P;
    }
    cout << solve() << endl;
    return 0;
}

