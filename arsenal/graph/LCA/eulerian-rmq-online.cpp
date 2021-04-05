#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int dfn[N << 1], dep[N << 1], dfntot = 0;
void dfs(int t, int depth) {
  dfn[++dfntot] = t;
  pos[t] = dfntot;
  dep[dfntot] = depth;
  for (int i = head[t]; i; i = side[i].next) {
    dfs(side[i].to, t, depth + 1);
    dfn[++dfntot] = t;
    dep[dfntot] = depth;
  }
}
void st_preprocess() {
  lg[0] = -1;  // 预处理 lg 代替库函数 log2 来优化常数
  for (int i = 1; i <= (N << 1); ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= (N << 1) - 1; ++i) st[0][i] = dfn[i];
  for (int i = 1; i <= lg[(N << 1) - 1]; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= ((N << 1) - 1); ++j) {
        st[i][j] = dep[st[i - 1][j]] < dep[st[i - 1][j + (1 << i - 1)]] ?
                   st[i - 1][j] : st[i - 1][j + (1 << i - 1)];
    }
  }
}

int main() {

}