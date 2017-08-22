#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
const int MOD = 10007;
int a[MAXN];
int sum[MAXN*4],  // the result we require for each node
    pre[MAXN*4],  // the sum of all prefix chain multiplications for each node
    suf[MAXN*4],  // the sum of all suffix chain multiplications for each node
    mul[MAXN*4];  // the chain multiplication of all numbers for each node
int n, q;

void push_up(int i) {
    int left = i*2, right = i*2+1;
    sum[i] = (sum[left] + sum[right] + suf[left]*pre[right]) % MOD;
    pre[i] = (pre[left] + mul[left]*pre[right]) % MOD;
    suf[i] = (suf[right] + mul[right]*suf[left]) % MOD;
    mul[i] = (mul[left]*mul[right]) % MOD;
}

void update(int i, int l, int r, int p, int v) {
    if (l == r) {
        sum[i] = pre[i] = suf[i] = mul[i] = v % MOD;
        return;
    }
    int mid = l+(r-l)/2;
    if (p <= mid) update(i*2, l, mid, p, v);
    else update(i*2+1, mid+1, r, p, v);
    push_up(i);
}

int main() {
    scanf("%d %d", &n, &q); 
    while (q--) {
        int p, v; scanf("%d %d", &p, &v);
        update(1, 1, n, p, v);
        printf("%d\n", sum[1]);
    }
    return 0;
}
