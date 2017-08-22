#include <iostream>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int calc(int k, int n) {
    if (n == 0) return 0;
    if (k%4 == 2 || k%4 == 3) return n;
    if (k%4 == 1) return calc(k/4+1, n-1);
    else return calc(k/4, n-1);
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int i, n;
        cin >> i >> n;
        cout << calc(i, n) << endl;
    }
    return 0;
}
