#include <iostream>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// A positive integer n can be written in prime factorization form:
//
//      n = p1^n1 * p2^n2 * p3^n3 * ... * pk^nk
//
// then, the number of all n's divisors is:
//
//      d = (n1+1) * (n2+1) * ... * (nk+1)


// http://hihocoder.com/discuss/question/2857/
// Given an integer n, for all integers not larger than n, find the integer with the most divisors.
// dfs + prune

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
