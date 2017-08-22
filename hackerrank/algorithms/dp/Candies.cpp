#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 1e5+5;
int rating[MAXN];
ll candy[MAXN];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> rating[i];
        candy[i] = 1;
    }
    ll res = 0;
    for (int i = 1; i < N; ++i)
        if (rating[i] > rating[i-1]) candy[i] = candy[i-1] + 1;
    for (int i = N-2; i >= 0; --i)
        if (rating[i] > rating[i+1]) candy[i] = max(candy[i], candy[i+1] + 1);
    for (int i = 0; i < N; ++i) res += candy[i];
    cout << res << endl;
    return 0;
}
