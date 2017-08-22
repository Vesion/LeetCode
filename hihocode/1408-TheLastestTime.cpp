#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(), a.end(), greater<int>());
    string res;
    do {
        int h = a[0]*10 + a[1];
        int m = a[2]*10 + a[3];
        if (h < 24 && m < 60) {
            res = (h < 10 ? "0" : "") + to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
            break;
        }
    } while (prev_permutation(a.begin(), a.end()));
    if (res.empty()) cout << "NOT POSSIBLE" << endl;
    else cout << res << endl;
    return 0;
}
