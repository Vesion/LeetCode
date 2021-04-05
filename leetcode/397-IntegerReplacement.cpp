#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// BFS
class Solution0 {
public:
    int integerReplacement(int n) {
        unordered_set<int> m;
        queue<int> q;
        q.push(n);
        m.insert(n);
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int t = q.front(); q.pop();
                if (t == 1) return res;
                if (t&1 && t != INT_MAX) {
                    if (!m.count(t+1)) q.push(t+1), m.insert(t+1);
                    if (!m.count(t-1)) q.push(t-1), m.insert(t-1);
                } else {
                    if (!m.count(t/2)) q.push(t/2), m.insert(t/2);
                }
            }
            ++res;
        }
        return res;
    }
};

// bitmap
// eliminate 1 as soon as possible, so:
// if n is even, n /= 2;
// if n is odd, if n = 0b...11, n += 1
//              if n = 0b...01, n -= 1
//              except n = 3, n -= 1
class Solution {
public:
    using ll = long long;
    int integerReplacement(int n) {
        int res = 0;
        ll ln = n;
        while (ln != 1) {
            if (ln&1) {
                if ((ln&3) == 1 || ln == 3) --ln;
                else ++ln;
            } else ln /= 2;
            ++res;
        }
        return res;
    }
};


int main() {
    return 0;
}
