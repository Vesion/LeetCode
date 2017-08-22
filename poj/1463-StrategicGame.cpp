#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1505;
vector<int> tree[MAXN];
bool inset[MAXN];
int N;
int res;

void dfs(int cur, int par) {
    bool flag = false;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        if (child == par) continue;
        dfs(child, cur);
        if (!inset[child]) flag = true;
    }
    if (flag) {
        inset[cur] = true;
        ++res;
    }
}

int main() {
    while (scanf("%d", &N) != EOF) {
        memset(inset, 0, sizeof inset);
        for (int i = 0; i < N; ++i) tree[i].clear();
        for (int i = 0; i < N; ++i) {
            int a, m; scanf("%d:(%d)", &a, &m);
            while (m--) { 
                int b; scanf("%d", &b); 
                tree[a].push_back(b);
                tree[b].push_back(a);
            }
        }
        res = 0;
        dfs(0, 0);
        printf("%d\n", res);
    }
    return 0;
}
