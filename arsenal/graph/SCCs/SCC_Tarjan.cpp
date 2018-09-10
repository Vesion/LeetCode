#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// http://hihocoder.com/discuss/question/2774/
//
// 2-sat problem, solved with SCC-Tarjan
// http://www.cppblog.com/sosi/archive/2010/09/26/127797.aspx

const int MAXN = 20010;

vector<int> g[MAXN];
int low[MAXN], dfn[MAXN], stamp;
int tp[MAXN], tpnum;
bool instack[MAXN];
stack<int> st;

void tarjan(int x) {
    dfn[x] = low[x] = ++stamp;
    st.push(x);
    instack[x] = true;
    for (int y : g[x]) {
        if (!dfn[y]) { // if not visit y yet
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else {
            if (instack[y]) // if y has been put into stack
                low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x]) { // x is root
        tpnum++;
        do {
            x = st.top(); st.pop();
            tp[x] = tpnum;
            instack[x] = false;
        } while (low[x] != dfn[x]);
    }
}

bool judge(int n) {
    for (int i = 0; i < n; ++i)
        if (tp[i<<1] == tp[i<<1|1]) return false; // 如果一对01节点处于同一个SCC中，则矛盾
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int N, M;
    while (T--) {
        for (auto &v : g) v.clear();
        memset(low, 0, sizeof low);
        memset(dfn, 0, sizeof dfn);
        memset(tp, 0, sizeof tp);
        memset(instack, 0, sizeof instack);
        stamp = tpnum = 0;
        while (!st.empty()) st.pop();

        cin >> N >> M;
        int x, y, s, x0, x1, y0, y1;
        while (M--) {
            cin >> x >> y >> s;
            x0 = x << 1; x1 = x0 | 1;
            y0 = y << 1; y1 = y0 | 1;
            if (s == 0) {
                g[x0].push_back(y1);
                g[y0].push_back(x1);
            } else {
                g[x1].push_back(y0);
                g[y1].push_back(x0);
            }
        }

        for (int i = 0; i < N*2; ++i) {
            if (!dfn[i])
                tarjan(i);
        }

        if (judge(N)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

