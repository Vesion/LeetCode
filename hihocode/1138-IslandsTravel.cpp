#include <iostream>
#include <cmath> 
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

const int MAX = 200000;
const int INF = 0x7fffffff;

struct Point {
    int x, y, id;
    bool operator<(const Point& p) const { return x < p.x; }
} p[MAX];

vector<pair<int, int>> edge[MAX]; // edge[i][j].first是与i点相连的点, edge[i][j].second是他们之间的距离

int N;    
bool inqueue[MAX];
int dist[MAX];


void build() {  
    sort( p , p + N );  
    for ( int i = 0; i < N; i ++ ) {  
        int j = i + 1;  
        int a = p[i].id;
        while ( j < N && p[j].x == p[i].x ) { //当两个点的x值相等时  
            int b = p[j].id; //排序后点的序号改变，不能直接用i表示，建立新的变量获取该点原来的序号  
            edge[a].push_back( make_pair( b , 0 ) );//建立一条从a到b的边，距离为0  
            edge[b].push_back( make_pair( a , 0 ) );//因为是无向图，同样建立一条从b到a的边，距离为0  
            j ++; //把所有x相等的点连起来  
        }  
        if ( i > 0 ) {  
            int b = p[i-1].id;
            edge[a].push_back( make_pair( b , p[i].x - p[i-1].x ) );  
            edge[b].push_back( make_pair( a , p[i].x - p[i-1].x ) );  
        }  
        i = j - 1; //因为while中进行j++操作，所以i要从最后一个x与前面一个点x值相同的点开始  
    } 
}  


void SPFA() {
    for (int i = 0; i < N; ++i) dist[i] = INF;
    dist[0] = 0;

    queue <int> q;  
    q.push(0);
    inqueue[0] = true;  
    while (!q.empty()) {  
        int now = q.front(); q.pop();
        inqueue[now] = false;  
        for (int i = 0; i < (int)edge[now].size(); ++i) { //遍历跟当前点有边的所有点  
            int nex = edge[now][i].first; //获得与当前点相连的点的编号  
            if ( dist[now] + edge[now][i].second < dist[nex] ) { //当前点到起点的距离+当前点到下一个点的距离<下一个点到起点的距离  
                dist[nex] = dist[now] + edge[now][i].second;  
                if ( inqueue[nex] == 0 ) { //如果下一个点不在队列中，入队；否则让它留在队中供其他点做判断  
                    q.push(nex);  
                    inqueue[nex] = 1 ;  
                }  
            }  
        }  
    }  
}


int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        p[i] = Point({x, y, i});
    }

    build(); // 按x建团
    for (int i = 0; i < N; ++i)
        swap(p[i].x, p[i].y);
    build(); // 按y建团

    SPFA();
    cout << dist[N-1] << endl;

    return 0;
}
