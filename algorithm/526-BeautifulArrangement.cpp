#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        if (N == 0) return 0;
        vector<int> m(1<<(N+1), -1);
        return dfs(1, N, 0, m);
    }
    
    int dfs(int start, int n, int used, vector<int>& m) {
        if (start == n+1) return 1;
        if (m[used] != -1) return m[used];
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!(used & (1<<i)) && (i%start == 0 || start%i == 0)) 
                res += dfs(start+1, n, used|(1<<i), m);
        }
        m[used] = res;
        return res;
    }
};


int main() {
    return 0;
}
