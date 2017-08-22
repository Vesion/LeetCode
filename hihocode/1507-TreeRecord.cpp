#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100005;
vector<pair<int,int>> tree[MAX];
int color[MAX];
pair<int,int> p[MAX];
vector<int> res;
int N;

void dfs(int curid, int parent) {
    int cur = curid == -1 ? 1 : tree[parent][curid].first;
    if (color[cur] == 1) {
        res.push_back(tree[parent][curid].second);
        return;
    } else if (color[cur] == 2) {
        res.push_back(tree[parent][curid].second);
        res.push_back(tree[p[cur].first][p[cur].second].second);
        return;
    }
    color[cur] = 1;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        dfs(i, cur);
    }
    p[cur] = {parent, curid};
    color[cur] = 2;
}


int main() {
    cin >> N; 
    for (int i = 1; i <= N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back({b, i});
    }
    dfs(-1, 1);
    sort(res.begin(), res.end());
    for (int& i : res) cout << i << " ";
    return 0;
}
