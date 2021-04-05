#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* nexts[26];
    TrieNode() : isEnd(false) { fill_n(nexts, 26, nullptr); }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    TrieNode* getRoot() { return root; }

    void insert(string word) {
        TrieNode* cur = root;
        for (auto &ch : word) {
            if (!cur->nexts[ch-'a']) cur->nexts[ch-'a'] = new TrieNode();
            cur = cur->nexts[ch-'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (auto &ch : word) {
            cur = cur->nexts[ch-'a'];
            if (!cur) return false;
        }
        return cur->isEnd == true;
    }
};


int main() {
    Trie trie;    
    trie.insert("abcd");
    cout << trie.search("abcd") << endl;
    return 0;
}
