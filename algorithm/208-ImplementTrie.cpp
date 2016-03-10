#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char val;
    bool isEnd;
    int shared; // the number of the node shared ,convenient to implement delete(string key), not necessary in this problem

    // Here we use vector to store all child pathes, bad performance in finding child.
    // Alternatively, we ought to use hash table to store pathes
    // 1. next[26] array, 2. hash table, are both much faster, but wasting memory
    vector<TrieNode*> children;

    TrieNode(char x) : val(x), isEnd(false), shared(0) {}
    TrieNode() : TrieNode(' ') {}
    TrieNode* getChild(char val) { // due to vector, this function is slow O(n)
        if (!children.empty())
            for (auto & c : children) if (c->val == val) return c;
        return NULL;
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        if (search(word)) return;
        TrieNode* cur = root;
        for (auto & ch : word) {
            TrieNode* child = cur->getChild(ch);
            if (child) cur = child;
            else {
                TrieNode* node = new TrieNode(ch);
                cur->children.push_back(node);
                cur = node;
            }
            ++cur->shared;
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;   
        for (auto & ch : word) {
            cur = cur->getChild(ch);
            if (!cur) return false;
        }
        return cur->isEnd == true;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto & ch : prefix) {
            cur = cur->getChild(ch);
            if (!cur) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("hello");
    cout << trie.search("hello") << endl;
    cout << trie.startsWith("hel") << endl;
    return 0;
}
