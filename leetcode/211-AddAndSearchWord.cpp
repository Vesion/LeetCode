#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class WordDictionary {
    struct Node {
        bool end;
        Node* next[26];
    };
    Node* root;

    bool dfs(const string& w, int i, Node* node) {
        if (!node) return false;
        if (i == w.size()) return node->end;
        char c = w[i];
        if (c == '.') {
            for (int j = 0; j < 26; ++j) {
                if (dfs(w, i+1, node->next[j])) return true;
            }
            return false;
        } else {
            return dfs(w, i+1, node->next[c-'a']);
        }
    }
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->next[c-'a'] == nullptr)
                cur->next[c-'a'] = new Node();
            cur = cur->next[c-'a'];
        }
        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};


int main() {
    return 0;
}
