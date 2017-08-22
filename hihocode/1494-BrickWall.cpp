#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
using namespace std;

int main() {
    unordered_map<int,int> m;
    int N; cin >> N; 
    for (int i = 0; i < N; ++i) {
        int C; cin >> C;
        int w; cin >> w;
        for (int j = 1; j < C; ++j) {
            m[w]++;
            int d; cin >> d; w += d;
        }
    }
    int res = N;
    for (auto& p : m) res = min(res, N-p.second);
    cout << res << endl;
    return 0;
}

