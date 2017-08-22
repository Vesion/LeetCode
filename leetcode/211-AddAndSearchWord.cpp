#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nexts[26];
        TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
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

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        insert(word);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string& word, int start, TrieNode* cur) {
        if (start == (int)word.size()) return cur->isEnd;
        char c = word[start];
        if (c != '.') {
            if (!cur->nexts[c-'a']) return false;
            return dfs(word, start+1, cur->nexts[c-'a']);
        } else {
            for (int i = 0; i < 26; ++i)
                if (cur->nexts[i] && dfs(word, start+1, cur->nexts[i])) return true;
            return false;
        }
    }
};


int main() {
    return 0;
}
