#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 3e5+5;
char s[MAXN];
int ta[10];
int K, M, B, N;

int powm(int x, int n) {
    int r = 1;
    while (n) {
        if (n&1) r = (r*x)%M;
        x = (x*x)%M;
        n /= 2;
    }
    return r;
}

int main() {
    scanf("%s", s);
    N = strlen(s);
    cin >> K >> B >> M;
    int p = powm(B, K-1);
    for (int i = 1; i < 10; ++i) ta[i] = (i*p) % M;

    int res = 0, sum = 0;
    int i = 0, j = 0;
    while (i < N) {
        sum = (sum*B + s[i++]-'0')%M;
        if (i-j == K) {
            res += sum;
            sum = (sum - ta[s[j++]-'0'] + M) % M;
        }
    }
    cout << res << endl;
    return 0;
}
