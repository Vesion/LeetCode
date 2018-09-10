#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map> 
using namespace std;

const int MAXN = 100005;

int N, M;
unordered_map<string, int> id; // hash each string name to a unique id
string name[MAXN]; // map id to original name

vector<int> tree[MAXN];
int color[MAXN];
unordered_map<int, vector<pair<int,int>>> query; // { query_name_1 : (query_name_2, query_id) }
int res[MAXN];

int root[MAXN];
int findRoot(int i) {
    if (root[i] != i) root[i] = findRoot(root[i]);
    return root[i];
}

void dfs(int cur, int parent) {
    color[cur] = 1;
    if (query.count(cur)) {
        for (auto& p : query[cur]) {
            int other = p.first;
            if (color[other] == 1) res[p.second] = other;
            else if (color[other] == 2) res[p.second] = findRoot(other);
        }
    }
    for (int& child : tree[cur]) dfs(child, cur);
    color[cur] = 2;
    root[cur] = parent;
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
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string c1, c2; cin >> c1 >> c2;
        int ic1 = id[c1], ic2 = id[c2];
        query[ic1].push_back({ic2, i});
        query[ic2].push_back({ic1, i});
    }

    for (int i = 0; i < MAXN; ++i) root[i] = i;
    dfs(0, 0);

    for (int i = 0; i < M; ++i) cout << name[res[i]] << endl;
    return 0;
}

