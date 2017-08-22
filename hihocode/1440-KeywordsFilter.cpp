#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

const int MAX_LEN = 100005;
int f[MAX_LEN];

struct TrieNode {
    int len;
    TrieNode* nexts[26];
    TrieNode* fail;
    TrieNode() { len = 0; fill_n(nexts, 26, nullptr); fail = nullptr; }
};

TrieNode* root;

void insert(string& word) {
    TrieNode* cur = root;
    for (char& c : word) {
        if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
        cur = cur->nexts[c-'a'];
    }
    cur->len = word.size();
}

void build() {
    queue<TrieNode*> q;
    q.push(root);
    while (!q.empty()) {
        TrieNode* cur = q.front(); q.pop();
        for (int i = 0; i < 26; ++i) {
            TrieNode* next = cur->nexts[i];
            TrieNode* t = (cur == root ? root : cur->fail->nexts[i]);
            if (!next) {
                cur->nexts[i] = t;
            } else {
                next->fail = t;
                q.push(next);
            }
        }
    }
}

void query(string& s) {
    TrieNode* cur  = root;
    for (int i = 0; i < (int)s.size(); ++i) {
        cur = cur->nexts[s[i]-'a'];
        TrieNode* p = cur;
        while (p != root) {
            if (p->len) { // here we just update left and right bounder, no need to update whole f[i-p->len+1...i+1]
                f[i-p->len+1]--;
                f[i+1]++;
                break; // long range must include short range
            }
            p = p->fail;
        }
    }
}


int main() {
    int n; cin >> n;
    root = new TrieNode();
    while (n--) {
        string word; cin >> word;
        insert(word);
    }
    build();
    string s; cin >> s;
    query(s);

    int c = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        c += f[i];
        if (c < 0) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}
