#include <iostream>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using ll = unsigned long long;

const int INF = 0x7FFFFFFF;

ll n;
ll prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll res, maxCnt;


void dfs(int pi, ll cur, ll cnt, int lastNi) {
    if (pi > 14) return;
    if (cnt > maxCnt || (cnt == maxCnt && cur < res)) {
        maxCnt = cnt;
        res = cur;
    }
    int i = 1;
    while (true) {
        cur *= prime[pi];
        if (cur > n || i > lastNi) break;
        dfs(pi+1, cur, cnt*(i+1), i);
        ++i;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n; 
    res = maxCnt = 1;
    dfs(0, 1, 1, INF);
    cout << res << endl;
    return 0;
}
