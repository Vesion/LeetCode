#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1e5+5;
int a[MAXN];
int N;

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (a[i] == 0) continue;
        int c = 0;
        int j = i;
        while (a[j]) {
            ++c;
            int t = a[j];
            a[j] = 0;
            j = t;
        }
        res = max(res, c);
    }
    cout << res << endl;
    return 0;
}
