#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dfs
class Solution {
public:
    const vector<int> valid = {0, 1, 6, 8, 9};
    vector<int> m;
    using ll = long long;

    int confusingNumberII(int N) {
        m = vector<int>(10);
        m[0] = 0, m[1] = 1, m[6] = 9, m[8] = 8, m[9] = 6;
        return dfs(0, 0, 1, N);
    }

    int dfs(ll num, ll rotate, ll digit, int N) {
        int res = 0;
        if (num != rotate) ++res;
        for (int v : valid) {
            if (num == 0 && v == 0) continue;
            if (num*10 + v <= N) res += dfs(num*10+v, m[v]*digit+rotate, digit*10, N);
        }
        return res;
    }
};

int main() {

}