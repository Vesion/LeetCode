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
ll a[MAXN];
int n;


int main() {
    cin >> n;
    ll left = LONG_MAX, right = LONG_MIN;
    double y = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        left = min(left, a[i]);
        right = max(right, a[i]);
        y += log2(a[i]);
    }

    while (left <= right) {
        ll mid = left+(right-left)/2;
        if (n*log2(mid) > y) right = mid-1;
        else left = mid+1;
    }
    cout << left << endl;

    return 0;
}
