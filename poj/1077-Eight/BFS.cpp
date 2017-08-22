#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// 八数码，经典搜索题


// Solution 1 : bfs, pointer, hash

struct Node {
    int b[9];
    int x, h;
    string path; };

const int MAX = 362880; // 9!
bool visited[MAX];

int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char mo[4] = {'u', 'd', 'l', 'r'};

int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; // 0!, 1!, ..., 9!
int hashBoard(int* b) {
    int num = 0;
    for (int i = 0; i < 9-1; i++) {
        int cnt = 0;
        for (int j = i + 1; j < 9; j++) {
            if (b[j] < b[i])
                cnt++;
        }
        num += fac[b[i] -1] * cnt;
    }
    return num;
}

void solve() {
    Node start;
    char c;
    for (int i = 0; i < 9; ++i) {
        cin >> c;
        if (c == 'x') start.x = i, start.b[i] = 9;
        else start.b[i] = c-'0';
    }
    start.h = hashBoard(start.b);

    queue<Node> q;
    q.push(start);

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        if (cur.h == 0) {
            cout << cur.path << endl;
            return;
        }

        int i = cur.x/3, j = cur.x%3;
        for (int g = 0; g < 4; ++g) {
            int ni = i+go[g][0], nj = j+go[g][1];
            if (ni < 0 || ni >= 3 || nj < 0 || nj >= 3) continue;
            Node next = cur;
            next.x = ni*3 + nj;
            swap(next.b[next.x], next.b[cur.x]);
            next.h = hashBoard(next.b);

            if (visited[next.h]) continue;
            visited[next.h] = true;

            next.path += mo[g];
            q.push(next);
        }
    }

    cout << "unsolvable" << endl;
    return;
}

int main() {
    solve();
    return 0;
}
