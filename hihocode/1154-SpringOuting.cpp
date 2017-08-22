#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1008;
int N, K;
int p[MAX][MAX];
int r[MAX];


int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K; 
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            int a;
            cin >> a;
            p[i][a] = j;
        }
    }

    r[K+1] = 0;
    for (int j = K; j >= 1; --j) {
        int v = 0;
        for (int i = 1; i <= N; ++i) {
            if (p[i][j] < p[i][r[j+1]])
                ++v;
        }
        if (v > N/2) r[j] = j;
        else r[j] = r[j+1];
    }
    if (r[1]) cout << r[1] << endl;
    else cout << "otaku" << endl;
    return 0;
}
