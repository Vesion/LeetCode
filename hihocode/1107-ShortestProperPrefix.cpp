#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INF = 0x7fffffff;


struct Node {
    int cnt;
    Node* next[26];
    Node(int val) : cnt(val) {
        fill_n(next, 26, nullptr);
    }
};

void insert(Node* root, string word) {
    Node* cur = root;
    for (auto &ch : word) {
        if (!cur->next[ch-'a']) cur->next[ch-'a'] = new Node(1);
        else cur->next[ch-'a']->cnt++;
        cur = cur->next[ch-'a'];
    }
}

int res;
void dfs(Node* root) {
    if (root->cnt <= 5) {
        res++;
        return;
    }
    for (int i = 0; i < 26; ++i) {
        if (root->next[i])
            dfs(root->next[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;    
    cin >> N;
    Node* root = new Node(INF);
    string s;
    while (N--) {
        cin >> s;
        insert(root, s);
    }
    res = 0;
    dfs(root);
    cout << res << endl;
    return 0;
}
