#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode* next[26];
    TrieNode() : isEnd(false) { fill_n(next, 26, nullptr); } // must memset here!
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->next[c-'a']) cur->next[c-'a'] = new TrieNode();
            cur = cur->next[c-'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};


int main() {
    Trie t;
    t.insert("helloworld");
    cout << t.search("helloworld") << endl;
    cout << t.startsWith("hello") << endl;
    return 0;
}

