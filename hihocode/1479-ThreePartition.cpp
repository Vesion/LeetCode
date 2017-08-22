#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://blog.csdn.net/viphong/article/details/61958631

const int MAXN = 100005;
int val[MAXN], sum[MAXN];
vector<int> tree[MAXN];
int N;
int root, one, two, target;
long long res;

void getSum(int cur) {
    sum[cur] = val[cur];
    for (int& child : tree[cur]) {
        getSum(child);
        sum[cur] += sum[child];
    }
}

void dfs(int cur) {
    if (sum[cur] == target) res += one + two; // add nodes sum to 1/3 at other substrees, and nodes sum to 2/3 in this substree (must be current's parent)
    if (cur != root && sum[cur] == 2*target) ++two;
    for (int& child : tree[cur])
        dfs(child);
    if (sum[cur] == target) ++one;
    if (cur != root && sum[cur] == 2*target) --two;
}

int main() {
    int T; cin >> T;    
    while (T--) {
        memset(val, 0, sizeof val);
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < MAXN; ++i) tree[i].clear();
        root = res = one = two = target = 0;
        int total = 0;

        cin >> N;
        for (int i = 1; i <= N; ++i) {
            int v, p; cin >> v >> p;
            if (p == 0) root = i;
            val[i] = v;
            total += v;
            tree[p].push_back(i);
        }
        if (total%3) { cout << 0 << endl; continue; }
        target = total / 3;

        getSum(root);
        dfs(root);
        cout << res << endl;
    }
    return 0;
}
