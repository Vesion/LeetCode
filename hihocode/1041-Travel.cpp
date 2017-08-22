#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset> 
using namespace std;

// 把题目中的序列称作S，树称作T。那么对于S中的任意节点x，x的子孙节点如果在S出现的话，那么这个子孙节点的位置是有一定要求的：x的所有子孙节点在S中的位置都恰好紧跟在x的后面，没有被其他节点隔开。 设x的子孙节点是abcd，那么--xabcd--, --xbcda-- 等等是合法的，--xab-cd--, --axbcd--, --x--abcd--, 都是不合法的('-'指其他节点)。对于S中每个节点都做如上判断，如果有不合法的就输出NO，如果都合法就输出YES。

const int MAX = 105;

// 因为题目给出的点是无序的，所以我们只能建立无向图，然后用flag数组标记走过的边
vector<int> tree[MAX];
bool flag[MAX][MAX];

// 巧用bitset，记录该节点能到达的所有节点
bitset<MAX> has[MAX];

int order[MAX], o;
int m, n;
bool ok;

void buildHas(int cur, int parent) {
    has[cur][cur] = 1;
    for (int& nbr : tree[cur]) {
        if (nbr == parent) continue;
        buildHas(nbr, cur);
        has[cur] |= has[nbr]; // merge results of children
    }
}

void dfs(int cur, int parent) {
    if (cur == order[o]) ++o;
    if (o == m) { ok = true; return; }
    while (o < m) {
        int t = o, c = order[o];
        for (int& nbr : tree[cur]) {
            if (nbr == parent) continue;
            if (has[nbr][c] && flag[cur][nbr]) {
                flag[cur][nbr] = false; // give it direction
                dfs(nbr, cur);
                break;
            }
        }
        if (t == o) break;
    }
}

int main() {
    int T; cin >> T;    
    while (T--) {
        memset(order, 0, sizeof order);
        memset(flag, 0, sizeof flag);
        for (int i = 0; i < MAX; ++i) {
            has[i].reset();
            tree[i].clear();
        }
        o = ok = 0;
        cin >> n;
        for (int i = 0; i < n-1; ++i) {
            int a, b; cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
            flag[a][b] = flag[b][a] = true;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) cin >> order[i];
        buildHas(1, -1);
        dfs(1, -1);
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
