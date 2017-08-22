#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set> 
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int P, Q;
    cin >> P >> Q;
    set<int> ps, qs;
    for (int i = 1; i <= P/2+1; ++i) {
        if (!(P%i)) {
            ps.insert(i);
            ps.insert(P/i);
        }
    }
    for (int i = 1; i <= Q/2+1; ++i) {
        if (!(Q%i)) {
            qs.insert(i);
            qs.insert(Q/i);
        }
    }
    for (int i : ps)
        for (int j : qs)
            cout << i << " " << j << endl;
    return 0;
}
