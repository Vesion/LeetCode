#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = (1<<11);
int a[MAXN];

int main() {
    for (int len = 1; len <= (1<<9); len *= 2) {
        for (int i = len; i < 2*len; ++i) a[i] = 1-a[i-len];
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << a[x] << endl;
    }
    return 0;
}
