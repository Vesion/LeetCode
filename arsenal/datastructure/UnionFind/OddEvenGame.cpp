#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// https://www.1point3acres.com/bbs/thread-738926-1-1.html
// For an array num[], A and B are playing a game:
// A will give B a sequence of queries, ranges [l, r] and the parity of sum of nums[l...r],
// B has to check the first range which its parity is deduced to be contrary with queries given before.

// extended union find
class Solution {
    // if parity of prefix sum of num[0...x] is equal to that of num[0...y]
    // we should have root[x] == root[y],
    // we always have root[x] != root[x+n]
    vector<int> root;
    int n;

    int find(int x) {
        return root[x] == x ? x : root[x] = find(root[x]);
    }

    bool query(int l, int r, bool odd) {
        int prel = l-1;
        if (!odd) {
            // if sum of num[l...r] is even, then
            // parity of prefix sum of num[0...l-1] = parity of prefix sum of num[0...r]
            root[find(prel)] = find(r);
            root[find(prel+n)] = find(r+n);
        } else {
            // otherwise, they are not equal
            root[find(prel)] = find(r+n);
            root[find(prel+n)] = find(r);
        }
        return find(prel) != find(prel+n);
    }
  public:
    int check(int N, const vector<vector<int>>& queries) {
        n = N;
        root.resize(n*2);  // extended
        iota(root.begin(), root.end(), 0);
        for (const auto& q : queries) {
            if (!query(q[0], q[1], q[2])) return false;
        }
        return true;
    }
};


// weighted union find
class Solution {
    int find(int x) {
        if(x != p[x]) {
            int rt = find(p[x]);
            d[x] ^= d[p[x]];
            p[x] = rt;
        }
        return p[x];
    }
    bool query(int a, int b, bool isOdd) {
            --a;       
            int pa = find(a), pb = find(b);
            if(pa != pb) p[pa] = pb, d[pa] = d[a] ^ d[b] ^ isOdd;
            else if(d[a] ^ d[b] ^ isOdd) return false;
    }
};

int main() {

}