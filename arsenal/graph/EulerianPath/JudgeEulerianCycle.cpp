#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 欧拉回路：图G，
// 若存在一条路，经过G中每条边有且仅有一次，称这条路为欧拉路径，
// 如果存在一条回路经过G每条边有且仅有一次，称这条回路为欧拉回路。具有欧拉回路的图成为欧拉图。

// 判断欧拉路是否存在的方法
// 有向图：图连通，有一个顶点出度大入度1，有一个顶点入度大出度1，其余都是出度=入度。
// 无向图：图连通，只有两个顶点是奇数度，其余都是偶数度的。

// 判断欧拉回路是否存在的方法
// 有向图：图连通，所有的顶点出度=入度。
// 无向图：图连通，所有顶点都是偶数度。

// 一般步骤:
// 1.利用并查集判断图是否连通，即判断p[i] < 0的个数，如果大于1，说明不连通。
// 2.根据出度入度个数，判断是否满足要求。
// 3.利用dfs输出路径。



// http://poj.org/problem?id=1386
// 判断能否将一串字符串收尾相连成一串

const int MAX = 26;

int root[MAX], ranks[MAX];

void makeset() {
    for (int i = 0; i < MAX; ++i) {
        root[i] = i;
        ranks[i] = 0;
    }
}

int findroot(int x) {
    if (x != root[x])
        root[x] = findroot(root[x]);
    return root[x];
}

void unionset(int x, int y) {
    int rx = findroot(x), ry = findroot(y);
    if (rx == ry) return;
    if (ranks[rx] > ranks[ry])
        root[ry] = rx;
    else {
        if (ranks[rx] == ranks[ry]) ++ranks[ry];
        root[rx] = ry;
    }
}

int ind[MAX], outd[MAX];
int g[MAX][MAX];
bool has[MAX];

// Directed Grapth
bool hasEulerPath() {
    int s = 0, e = 0;
    bool flag = true;
    for (int i = 0; i < MAX; ++i) {
        if (has[i] && outd[i] != ind[i]) {
            if (outd[i] == ind[i]+1) s++;
            else if (ind[i] == outd[i]+1) e++;
            else flag = false;
        }
    }
    return flag && ((s == 1 && e == 1) || (s == 0 && e == 0));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(ind, 0, sizeof ind);
        memset(outd, 0, sizeof outd);
        memset(g, 0, sizeof g);
        memset(has, false, sizeof has);
        makeset();

        int n;
        cin >> n;
        while (n--) {
            string s;
            cin >> s;
            int start = s[0]-'a', end = s[s.size()-1]-'a';
            has[start] = has[end] = true;
            outd[start]++;
            ind[end]++;
            unionset(start, end);
        }
        
        int c = 0;
        for (int i = 0; i < MAX; ++i)
            if (has[i] && findroot(i) == i) ++c;
        if (c > 1) {
            cout << "The door cannot be opened." << endl;
            continue;
        }

        if (hasEulerPath())
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
    }
    return 0;
}
