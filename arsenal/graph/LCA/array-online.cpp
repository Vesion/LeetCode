#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
using namespace std;

const int MAXN = 100100;
int N, M;
vector<int> tree[MAXN];
unordered_map<string, int> id;
string name[MAXN];
int num[2*MAXN], k;
int pos[MAXN];
int depth[MAXN];

void dfs(int cur, int d) {
    depth[cur] = d;
    pos[cur] = k;
    num[k++] = cur;
    for (int& child : tree[cur]) {
        dfs(child, d+1);
        pos[cur] = k;
        num[k++] = cur;
    }
}

int main() {
    cin >> N;
    int t = 0;
    for (int i = 0; i < N; ++i) {
        string p, c; cin >> p >> c;
        if (!id.count(p)) id[p] = t++;
        if (!id.count(c)) id[c] = t++;
        tree[id[p]].push_back(id[c]);
        name[id[p]] = p; name[id[c]] = c;
    }

    k = 0;
    dfs(0, 0);

    cin >> M;
    while (M--) {
        string c1, c2; cin >> c1 >> c2;
        int p1 = pos[id[c1]], p2 = pos[id[c2]];
        if (p1 > p2) swap(p1, p2);
        int res = num[p1], mind = depth[num[p1]];
        for (int i = p1; i <= p2; ++i) {
            if (depth[num[i]] < mind) {
                mind = depth[num[i]];
                res = num[i];
            }
        }
        cout << name[res] << endl;
    }
    return 0;
}

