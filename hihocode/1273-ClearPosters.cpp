#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

const int N = 1005;
struct node{
	int x1, y1, x2, y2;
	void read() {scanf("%d%d%d%d", &x1, &y1, &x2, &y2);}
	bool cover(int x, int y) {
		return x > x1 && x < x2 && y > y1 && y < y2;
	}
}a[N];
int out[N], ans[N], cnt;
bool can[N], vis[N];
vector <int> v[N];

inline bool cover(node A, node B) {
	if(A.x2 <= B.x1) return 0;
	if(A.y2 <= B.y1) return 0;
	if(A.x1 >= B.x2) return 0;
	if(A.y1 >= B.y2) return 0;
	return 1;
}
bool flag[4];
queue <int> q;

void go(int x) {
	if(vis[x]) return;
	vis[x] = 1;
	cnt++;
	for(int y: v[x]) {
		go(y);
	}
}

int main() {
	int n, w, h, mx, k;

	scanf("%d%d%d", &w, &h, &n);
	For(i, n) a[i].read();
	For(i, n) {
		mst(flag, 0);
		for(int j = i + 1; j < n; j++) {
			flag[0] |= a[j].cover(a[i].x1, a[i].y1);
			flag[1] |= a[j].cover(a[i].x1, a[i].y2);
			flag[2] |= a[j].cover(a[i].x2, a[i].y1);
			flag[3] |= a[j].cover(a[i].x2, a[i].y2);
			if(cover(a[i], a[j])) {
				v[i].push_back(j);
				out[i]++;
			}
		}
		can[i] = 0;
		For(j, 4) if(!flag[j]) can[i] = 1;
	}

	mx = 0;
	For(i, n) {
		if(!can[i]) continue;
		mst(vis, 0);
		cnt = 0;
		go(i);
		if(cnt > mx) {
			mx = cnt;
			k = i;
		}	
	}

	printf("%d %d\n", mx, k + 1);
	return 0;
}

