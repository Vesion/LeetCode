#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <queue> 
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> g[MAXN];
int dist[MAXN];
bool has[MAXN];
int N, M, S, T;


void spfa(int s) {  
    for (int i = 1; i <= N; ++i) dist[i] = INT_MAX;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    has[s] = true;
    while(!q.empty()) {
        int i = q.front(); q.pop();
        has[i] = false;
        for(auto& p : g[i]) {
            int j = p.first, l = p.second;
            if(dist[j] > dist[i]+l) {
                dist[j] = dist[i]+l;
                if(!has[j]) {
                    q.push(j);
                    has[j] = true;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M >> S >> T; 
    while (M--) {
        int a, b, l; cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    spfa(S);
    cout << dist[T] << endl;
    return 0;
}
