#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using uint = unsigned int;

struct Node {
    int order; 
    Node* next[2];
    Node() : order(0) {}
};

Node* pool;
Node* root;
int id;

Node* getNode() { return pool+(id++); }

void insert(uint ip, int mask, int order) {
    Node* cur = root;
    for (int i = 0; i < mask; ++i) {
        if (cur->order) return;
        int bit = (ip >> (31-i)) & 1;
        if (!cur->next[bit]) cur->next[bit] = getNode();
        cur = cur->next[bit];
    }
    if (!cur->order) cur->order = order;
}

int query(uint req) {
    Node* cur = root;
    int res = 1;
    for (int i = 0; i < 32; ++i) {
        if (cur->order) res = cur->order;
        int bit = (req >> (31-i)) & 1;
        if (!cur->next[bit]) break;
        cur = cur->next[bit];
    }
    return res;
}

uint getIp() {
    uint a, b, c, d;
    char t;
    cin >> a >> t >> b >> t >> c >> t >> d;
    return (a << 24) | (b << 16) | (c << 8) | d;
}

int main() {
    pool = new Node[3200005];
    id = 0;
    root = getNode();

    int n, m;
    cin >> n >> m;
    string cmd;
    char t;
    for (int i = 1; i <= n; ++i) {
        cin >> cmd;
        uint ip = getIp();
        int mask = 32;
        cin >> t;
        if (t == '/') cin >> mask;
        else cin.putback(t);
        int order = i;
        if (cmd != "allow")
            order *= -1;
        insert(ip, mask, order);
    }
    for (int i = 0; i < m; ++i) {
        uint ip = getIp();
        cout << (query(ip) < 0 ? "NO" : "YES") << endl;
    }
    return 0;
}
