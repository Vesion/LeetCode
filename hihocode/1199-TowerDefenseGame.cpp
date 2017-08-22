#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 10008;
const int INF = 200000000;

int n;
int p[MAX], q[MAX]; // 每个节点的p, q
int pt[MAX], qt[MAX]; // 遍历这棵子树需要的钱数，遍历这课子树反还的钱数
bool v[MAX];
vector<int> tree[MAX];

bool comp(const int a, const int b) {
    return qt[a] > qt[b];
}

void dfs(int root) {
    int W = INF; // 当前钱包的钱数
    int minW = INF; // 钱包中的钱数最少时的钱数, 花费的钱数
    v[root] = true;
    for (int node : tree[root]) {
        if (!v[node]) {
            dfs(node);
            v[node] = false;
        }
    }
    sort(tree[root].begin(), tree[root].end(), comp);
    W -= p[root];
    minW = min(minW, W);
    W += q[root];
    for (int node : tree[root]) {
        if (!v[node]) {
            W -= pt[node];
            minW = min(minW, W);
            W += qt[node];
        }
    }
    pt[root] = INF - minW;
    qt[root] = W - minW;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i] >> q[i];
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    cout << pt[1] << endl;
    return 0;
}
