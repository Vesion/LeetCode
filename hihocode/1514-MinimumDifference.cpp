#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 100005;
const int INF = 0x7fffffff;
pair<int,int> x[3*MAXN];
int id[3] = {-1, -1, -1};
int N, M, L;

int getD() {
    for (int i = 0; i < 3; ++i) if (id[i] == -1) return INF;
    int d = 0;
    d += abs(x[id[0]].first-x[id[1]].first);
    d += abs(x[id[1]].first-x[id[2]].first);
    d += abs(x[id[2]].first-x[id[0]].first);
    return d;
}

int main() {
    cin >> N >> M >> L; 
    int n = N+M+L;
    for (int i = 0; i < N; ++i) { cin >> x[i].first; x[i].second = 0; }
    for (int i = N; i < N+M; ++i) { cin >> x[i].first; x[i].second = 1; }
    for (int i = N+M; i < N+M+L; ++i) { cin >> x[i].first; x[i].second = 2; }
    sort(x, x+n);
    int mind = INF;
    for (int i = 0; i < n; ++i) {
        id[x[i].second] = i;
        mind = min(mind, getD());
    }
    cout << mind << endl;
    return 0;
}
