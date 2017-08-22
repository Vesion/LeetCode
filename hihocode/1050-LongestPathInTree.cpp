#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100005;

vector<int> tree[MAX];
int ins[MAX];
int N;
int res;

int dfs(int cur, int parent) {
    int first = -1, second = -1;
    for (int& nbr : tree[cur]) {
        if (nbr == parent) continue;
        int t = dfs(nbr, cur);
        if (t > first) { second = first; first = t; }
        else if (t > second) second = t;
    }
    res = max(res, first+second+2);
    return first+1;
}

int main() {
    memset(ins, 0, sizeof ins);
    cin >> N; 
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        ++ins[a]; ++ins[b];
    }
    res = 0;
    dfs(1, 0);
    cout << res << endl;
    return 0;
}
