#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 105;
int g[MAXN][MAXN];
int c[MAXN];
int b[MAXN];
int N;

int main() {
    int T; cin >> T;
    while (T--) {
        memset(c, 0, sizeof c);
        memset(b, 0, sizeof b);
        cin >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> g[i][j];
                c[i] += g[i][j];
            }
        }
        for (int j = 0; j < N; ++j) for (int i = 0; i < N; ++i) b[j] += g[i][j];
        sort(c, c+N);
        sort(b, b+N);
        bool res = true;
        for (int i = 0; i < N; ++i) if (c[i] != b[i]) res = false;
        if (res) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}
