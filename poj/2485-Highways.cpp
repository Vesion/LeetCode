#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 512;
const int inf = (1<<16)+10;

int N;
int g[MAX][MAX];
bool u[MAX]; // record the point which in in MST
int d[MAX]; // the distance between outside points and MST

int mst_prim() {
    memset(u, false, sizeof u);
    u[1]=true; // add 1st point into MST
    for (int i = 1; i <= N; ++i) d[i] = g[1][i]; // init distances

    int s; // track outside candidate point

    int result = 0;

    for (int i = 1; i < N; ++i) {
        int w = inf;
        for (int j = 1; j <= N; ++j) { // try to find out a point which is nearest to MST
            if (!u[j] && d[j] < w) {
                w = d[j];
                s = j;
            }
        }
        u[s] = true; // add it into MST

        result = max(result, w); // 这题要求的是最长的边，不是所有边的和

        for (int j = 1; j <= N; ++j) { // relax edges out of MST
            if (!u[j] && d[j] > g[s][j])
                d[j] = g[s][j];
        }
    }

    return result;  
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                cin >> g[i][j];
        cout << mst_prim() << endl;
    }
    return 0;
}
