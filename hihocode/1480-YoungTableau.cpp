#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 100;
const int MOD = 1000000007;
int N, M;
long long F[MAXN * 3];

long long calc_pow(long long x, int y)
{
    if (y == 0) return 1LL;
    long long z = calc_pow(x, y / 2);
    z = z * z % MOD;
    if (y % 2 == 1) z = z * x % MOD;
    return z;
}

long long inv(long long x)
{
    return calc_pow(x, MOD - 2);
}

long long calc2(int N)
{
    long long Ret = F[N*2];
    Ret = (Ret * inv(F[N])) % MOD;
    Ret = (Ret * inv(F[N+1])) % MOD;
    return Ret;
}

long long calc3(int N)
{
    long long Ret = F[N*3] * 2LL % MOD;
    Ret = (Ret * inv(F[N])) % MOD;
    Ret = (Ret * inv(F[N+1])) % MOD;
    Ret = (Ret * inv(F[N+2])) % MOD;
    return Ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    F[0] = 1;
    for (int i = 1; i <= 3 * M; i ++) {
        F[i] = (F[i-1] * i) % MOD;
    }
    if (N == 1) {
        printf("1\n");
    } else if (N == 2) {
        printf("%lld\n", calc2(M));
    } else {
        printf("%lld\n", calc3(M));
    }
    return 0;
}

