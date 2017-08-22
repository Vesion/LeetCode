#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

const int MAXN = 1005;
int a[MAXN], pos[MAXN];
int N;

// Solution 1 : simulate straight-forward, O(N^2)
bool solve_1() {
    for (int i = 1; i <= N; ++i) {
        if (pos[i] == i) continue;
        if (i == N-1) return false;
        while (pos[i] != i) {
            int j = pos[i];
            if (pos[i]-i >= 2) {
                a[j] = a[j-1]; pos[a[j]]++;
                a[j-1] = a[j-2]; pos[a[j-1]]++;
                a[j-2] = i; pos[i] -= 2;
            } else {
                a[j] = a[j+1]; pos[a[j]]--;
                a[j+1] = a[j-1]; pos[a[j+1]] += 2;
                a[j-1] = i; pos[i]--;
            }
        }
    }
    return true;
}


// Solution 2 : find the property of inversions
//      Let M be the number of inverions of an array
//          M of [0, 1, ..., N-1, N] is 0,
//          M of [0, 1, ..., N, N-1] is 1
//      then shift operation won't change the parity of M (why?), so we only need to find the parity of M
// Here is O(N^2), but can be done in O(NlogN) with merge sort / segment tree
bool solve() {
    int M = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            M ^= (a[i] > a[j]);
        }
    }
    return M == 0;
}


int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        bool r = solve();
        if (r) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
