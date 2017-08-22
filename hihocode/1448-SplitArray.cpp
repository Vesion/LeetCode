#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

string solve() {
    int N, K;
    cin >> N >> K;
    if (N % K) return "NO";
    unordered_map<int,int> m;
    int start, end;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        if (i == 0) start = x;
        if (i == N-1) end = x;
        ++m[x];
    }
    int t = N / K;
    while (t > 0) {
        int c = m[start];
        for (int i = start; i < start+K; ++i) {
            if (m[i] < c) return "NO";
            m[i] -= c;
        }
        t -= c;
        for (int i = start+1; i <= end; ++i) {
            if (m[i]) { start = i; break; }
        }
    }
    return "YES";
}

int main() {
    int cases; cin >> cases;
    while (cases--) {
        cout << solve() << endl;
    }
    return 0;
}
