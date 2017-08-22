#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;
long long N, M;
long long result = 0;

void dfs(long long pre, long long sum, long long product) {
    if (sum == N) {
        if (product % M == 0) ++result;
        return;
    }
    for (int i = pre+1; i+sum <= N; ++i)
        dfs(i, i+sum, product*i);
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N >> M;
    dfs(0, 0, 1);
    cout << result <<endl;

    return 0;
}
