#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// Use array to simulate trie, suitable for situations when trie node dosn't have many properties, and it's easy to know the total number of nodes.
//
// Problem:
//      Given an array with size N, find the maximum XOR of two numbers in the array.
// Solution:
//      We can use array to simulate the trie, rather than a structure with 2 pointers.

const int MAXN = 1e5+5;
const int MAXL = 32;
int a[MAXN];
int to[2*MAXN*MAXL][2], ptr; // trie, node
int N;

void insert(int x) {
    int cur = 0;
    for (int i = MAXL-1; i >= 0; --i) {
        int bit = (x>>i)&1;
        if (!to[cur][bit]) to[cur][bit] = ptr++;
        cur = to[cur][bit];
    }
}

int query(int x) {
    int cur = 0;
    int res = 0;
    for (int i = MAXL-1; i >= 0; --i) {
        int bit = (x>>i)&1;
        if (to[cur][!bit]) {
            res |= (1<<i);
            cur = to[cur][!bit];
        } else cur = to[cur][bit];
    }
    return res;
}

int main() {
    cin >> N;
    ptr = 1;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}
