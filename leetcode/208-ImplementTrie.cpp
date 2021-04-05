#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Trie {
    struct Node {
        bool end;
        Node* next[26];
    };
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int t = c-'a';
            if (!cur->next[t]) cur->next[t] = new Node();
            cur = cur->next[t];
        }
        cur->end = true;
    }

    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            int t = c-'a';
            if (!cur->next[t]) return false;
            cur = cur->next[t];
        }
        return cur->end;
    }

    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            int t = c-'a';
            if (!cur->next[t]) return false;
            cur = cur->next[t];
        }
        return true;
    }
};


int main() {
    return 0;
}
