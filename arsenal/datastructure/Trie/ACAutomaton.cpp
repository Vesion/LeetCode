#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Aho-Corasick Algorithm (ACAutomata) is a classical algorithm used for multi pattern searching.
// It is based on Trie and KMP.
// Here we implement Trie Graph, the improved ACAutomata.
//
// Problem:
//      Given a dictionary words and a string s,
//      find all positions in s where word appears and word must be in dictionary.


class ACAutomata {
private:
    struct TrieNode {
        int len; // when word ends, store its length
        TrieNode* nexts[26];
        TrieNode* fail;
        TrieNode() { len = 0; fill_n(nexts, 26, nullptr); fail = nullptr; }
    };

    TrieNode* root;

public:
    ACAutomata() {
        root = new TrieNode();
    }

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
                if (next) {
                    next->fail = t;
                    q.push(next);
                } else {
                    cur->nexts[i] = t;
                }
            }
        }
    }

    void query(string& s) {
        TrieNode* cur = root;
        for (int i = 0; i < (int)s.size(); ++i) {
            cur = cur->nexts[s[i]-'a'];
            TrieNode* p = cur;
            while (p != root) {
                if (p->len) { // find a valid word
                    cout << i-p->len+1 << " " << i << endl;
                }
                p = p->fail;
            }
        }
    }
};


int main() {
    string s = "yasherhs";
    vector<string> words = {"say", "she", "shr", "he", "her"};
    ACAutomata ac;
    for (string& w : words) ac.insert(w);
    ac.build();
    ac.query(s);
    return 0;
}

