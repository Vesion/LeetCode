#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue> 
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* nexts[26];
    TrieNode* fail;
    TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); fail = nullptr; }
};

TrieNode* root;

void insert(string& word) {
    TrieNode* cur = root;
    for (char& c : word) {
        if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
        cur = cur->nexts[c-'a'];
    }
    cur->isEnd = true;
}

void build() {
    queue<TrieNode*> q;
    q.push(root);
    while (!q.empty()) {
        TrieNode* cur = q.front(); q.pop();
        for (int i = 0; i < 26; ++i) {
            TrieNode* next = cur->nexts[i];
            TrieNode* p = cur == root ? root : cur->fail->nexts[i];
            if (next) {
                next->fail = p;
                q.push(next);
            } else cur->nexts[i] = p;
        }
    }
}

bool query(string& s) {
    TrieNode* cur = root;
    for (char& c : s) {
        cur = cur->nexts[c-'a'];
        if (cur->isEnd) return true;
    }
    return false;
}

int main() {
    root = new TrieNode();
    int N; cin >> N; 
    while (N--) {
        string word; cin >> word;
        insert(word);
    }
    build();
    string s; cin >> s;
    if (query(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

