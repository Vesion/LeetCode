#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <queue> 
using namespace std;

// A classical search problem Eight Digit
// http://poj.org/problem?id=1077

const int MAX = 400000;
struct State {  
    int pre, pos, id, dir, g, f;
    char x[9];  
    State() : dir(-1) {}  
    State(int pre, int pos, int id, int dir, char t[])
        : pre(pre), pos(pos), id(id), dir(dir) { strcpy(x, t); }  
    bool operator <(const State &t) const { return f > t.f; }  
} p[MAX];


int go[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};  
bool v[MAX];  
int targetID;

int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int hashBoard(char* x) {  
    int h = 0;  
    for(int i = 1; i < 9; i++)  
    {  
        int count = 0;  
        for(int j = 0; j <i ; j++)  
            if(x[j] > x[i]) count++;  
        h += count * fac[i];  
    }  
    return h;  
}  

int h(State &t) {
    int sum = 0;  
    for(int i = 0; i < 3; i++)  
        for(int j = 0; j < 3; j++)  
        {  
            int k = i * 3 + j;  
            if(t.x[k] == 'x') continue;  
            sum += abs(i - (t.x[k] - '1') / 3) + abs(j - (t.x[k] - '1') % 3); // Manhattan Distance
        }  
    return sum;  
}  

void printPath(State& t) {  
    string path;
    char c[] = "lurd";
    while(t.pre != -1)  {  
        path += c[t.dir];
        t = p[t.pre];  
    }  
    reverse(path.begin(), path.end());  
    cout << path << endl;
}  

priority_queue<State>q;  
void Astar() {
    while(!q.empty())  
    {  
        State t = q.top();  
        q.pop();  
        if(t.id == targetID) {
            printPath(t);
            return;
        }
        int i = t.pos/3, j = t.pos%3; 
        for(int d = 0; d < 4; d++)  {  
            int ni = i + go[d][0], nj = j + go[d][1];
            if(ni < 0 || ni >= 3 || nj < 0 || nj >= 3) continue;  
            int np = ni*3 + nj;
            char nx[9];  
            strcpy(nx, t.x);  
            swap(nx[np], nx[t.pos]);  
            int nid = hashBoard(nx);
            if (v[nid]) continue;
            v[nid] = true;
            State n(t.id, np, nid, d, nx); 
            n.g = t.g+1;
            n.f = n.g + h(n);
            p[n.id] = n;  
            q.push(n);  
        }  
    }  
}


int main()  
{  
    State start;  
    for(int i = 0; i < 9; i++) {  
        scanf("%s", &start.x[i]);  
        if(start.x[i] == 'x') start.pos = i;  
    }  
    start.pre = -1;  
    start.id = hashBoard(start.x);  
    start.g = 0;  
    start.f = start.g + h(start);  
    p[start.id] = start;  
    q.push(start);  
    v[start.id] = true; 

    char target[] = "12345678x";  
    targetID = hashBoard(target);
    Astar();
    return 0;  
} 
