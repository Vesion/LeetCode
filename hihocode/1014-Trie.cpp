#include <cstdio> 
#include <cstring> 

struct TrieNode {
    int count;
    TrieNode* nexts[26];
    TrieNode() { count = 0; memset(nexts, 0, 26); }
};

TrieNode* root;
char s[15];


void insert(char* s) {
    TrieNode* cur = root;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int id = s[i]-'a';
        if (!cur->nexts[id]) cur->nexts[id] = new TrieNode();
        cur = cur->nexts[id];
        ++cur->count;
    }
}

int query(char* s) {
    TrieNode* cur = root;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int id = s[i]-'a';
        if (!cur->nexts[id]) return 0;
        cur = cur->nexts[id];
    }
    return cur->count;
}


int main() {
    root = new TrieNode();
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        insert(s);
    }
    int m; scanf("%d", &m);
    while (m--) {
        scanf("%s", s);
        printf("%d\n", query(s));
    }
    return 0;
}
