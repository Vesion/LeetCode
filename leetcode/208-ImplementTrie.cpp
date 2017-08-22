#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Trie {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nexts[26];
        TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
    };
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (!cur->nexts[c-'a']) return false;
            cur = cur->nexts[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char& c : prefix) {
            if (!cur->nexts[c-'a']) return false;
            cur = cur->nexts[c-'a'];
        }
        return true;
    }
};


int main() {
    return 0;
}
