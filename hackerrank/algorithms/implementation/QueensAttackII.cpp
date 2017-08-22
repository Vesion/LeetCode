#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int N, K;
int si, sj;
int go[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
pair<int,int> obs[8] = {{0,0}, {0,0}, {0,0}, {0,0}, {MAXN,MAXN}, {MAXN,MAXN}, {MAXN,MAXN}, {MAXN,MAXN}};

bool valid(int i, int j, int d) {
    if (i < 1 || i > N || j < 1 || j > N) return false;
    if (obs[d].first == i && obs[d].second == j) return false;
    return true;
}

int solve() {
    int res = 0;
    for (int d = 0; d < 8; ++d) {
        int i = si, j = sj;
        while (valid(i, j, d)) {
            i += go[d][0], j += go[d][1];
            ++res;
        }
    }
    return res-8;
}

int main() {
    cin >> N >> K; 
    cin >> si >> sj; si = N+1-si;
    while (K--) {
        int i, j; cin >> i >> j; i = N+1-i;
        if (i < si && j < sj && abs(i-si) == abs(j-sj)) obs[0] = max(obs[0], {i, j});
        else if (i < si && j == sj) obs[1] = max(obs[1], {i, j});
        else if (i < si && j > sj && abs(i-si) == abs(j-sj)) obs[2] = max(obs[2], {i, j});
        else if (i == si && j < sj) obs[3] = max(obs[3], {i, j});
        else if (i == si && j > sj) obs[4] = min(obs[4], {i, j});
        else if (i > si && j < sj && abs(i-si) == abs(j-sj)) obs[5] = min(obs[5], {i, j});
        else if (i > si && j == sj) obs[6] = min(obs[6], {i, j});
        else if (i > si && j > sj && abs(i-si) == abs(j-sj)) obs[7] = min(obs[7], {i, j});
    }
    cout << solve() << endl;
    return 0;
}
