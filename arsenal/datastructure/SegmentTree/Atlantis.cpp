#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 1000;

double sum[MAX];  // 线段树中的节点值，线段长度
int flag[MAX];    // 标记该节点是否有值
double ys[MAX];   // 记录所有不同的y值，用于离散化

// 竖边
struct Line {
    double x, y1, y2;
    int flag;
    Line() {}
    Line(double a, double b, double c, int f) : x(a), y1(b), y2(c), flag(f) {}
    bool operator< (const Line& n) const { return x < n.x; }
} lines[MAX];


// 若该节点是矩形左边的边，则计算距离
void push_up(int i, int l, int r) {
	if (flag[i]) sum[i] = ys[r] - ys[l];	
	else {
        if (l == r) sum[i] = 0; // 不需要这句话，因为前闭后开区间表示节点，l不可能等于r
        else sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
}

// 跟一般RMQ不同，这里用前闭后开区间表示节点，为什么？
// [l, r)表示线段的左端点为l，右端点为r，这样更符合“节点的值表示的是一条线段的距离”这一含义，
// 最底层的叶子节点[l, l+1)即为单位长度线段，它是有长度的，如果用一般的双闭区间就不太直观。
void update(int i, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		flag[i] += v;
		push_up(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	if (L < m) update(i*2, l, m, L, R, v);
	if (R > m) update(i*2+1, m, r, L, R, v);
    push_up(i, l, r);
}


int main() {
    int n, cases = 1;
    while (cin >> n && n > 0) {
        memset(sum, 0, sizeof sum);
        memset(flag, 0, sizeof flag);
        memset(ys, 0, sizeof ys);

        double x1, y1, x2, y2;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            lines[i*2] = Line(x1, y1, y2, 1);
            lines[i*2+1] = Line(x2, y1, y2, -1);
            ys[s++] = y1; ys[s++] = y2;
        }
        n *= 2;

        sort(lines, lines+n);
        sort(ys, ys+s);
        s = unique(ys, ys+s) - ys;

        double result = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) result += (lines[i].x - lines[i-1].x) * sum[1];
            int l = lower_bound(ys, ys+s, lines[i].y1) - ys;
            int r = lower_bound(ys, ys+s, lines[i].y2) - ys;
            update(1, 0, s-1, l, r, lines[i].flag);
        }

        printf("Test case #%d\n", cases++);
        printf("Total explored area: %.2lf\n\n", result);
    }
        
    return 0;
}

