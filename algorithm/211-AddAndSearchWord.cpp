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
        TrieNode() : isEnd(false) { fill_n(nexts, 26, nullptr); };
    };

    TrieNode* root;

    bool dfs(string& word, int start, TrieNode* cur) {
        if (!cur) return false;
        if (start == (int)word.size()) return cur->isEnd;
        if (word[start] != '.') return dfs(word, start+1, cur->nexts[word[start]-'a']);
        for (int i = 0; i < 26; ++i)
            if (dfs(word, start+1, cur->nexts[i])) return true;
        return false;
    }

public:
    
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

int main() {
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    cout << w.search("pad") << endl;
    cout << w.search("bad") << endl;
    cout << w.search(".ad") << endl;
    cout << w.search("b..") << endl;
    return 0;
}

