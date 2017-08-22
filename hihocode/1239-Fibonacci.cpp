#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;


int main() {
    ios::sync_with_stdio(false);

    vector<int> f(1, 0);
    int f1 = 0, f2 = 1;
    while (f2 < MAX) {
        f.push_back(f2);
        int t = f2;
        f2 = f1 + f2;
        f1 = t;
    }

    vector<int> dp(f.size(), 0);
    dp[0] = 1;
    int n; 
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = f.size()-1; a <= f[j] && j >= 1; --j)
            if (a == f[j])
                dp[j] = (dp[j] + dp[j-1]) % MOD;
    }

    int res = 0;
    for (int i = 1; i < MAX; ++i) {
        res = (res + dp[i]) % MOD;
    }
    
    cout << res << endl;
    return 0;
}
