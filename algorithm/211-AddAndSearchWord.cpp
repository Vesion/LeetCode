#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// This problem is an application of the Trie data structure (208-ImplementTrie)

// Differ from 208, this time we use array[26] rather than vector to get good performance.
// And TrieNode we do not include 'val' field. In other words, key is value.

class TrieNode {
public :
    bool isEnd;
    TrieNode* children[26];
    TrieNode() : isEnd(false) {
        for (auto &c : children) c = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() { root = new TrieNode(); } 

    void addWord(string word) {
        TrieNode* cur = root;
        for (auto & ch : word) {
            if (!cur->children[ch - 'a'])
                cur->children[ch - 'a'] = new TrieNode();
            cur = cur->children[ch - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        return query(word, 0, root);
    }

private:
    TrieNode* root;
    
    // use DFS to implement matching regex '.'
    bool query(string& word, int start, TrieNode* node) {
        TrieNode* cur = node;
        for (int i = start; i < word.size(); ++i) {
            if (cur && word[i] != '.')
                cur = cur->children[word[i] - 'a'];
            else if (cur && word[i] == '.') {
                TrieNode* tmp = cur;
                for (int j = 0; j < 26; ++j) {
                    cur = tmp->children[j];
                    if (query(word, i+1, cur)) return true;
                }
            }
            else break;
        }
        return cur && cur->isEnd;
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("abcd");
    cout << wd.search("abcd") << endl;
    cout << wd.search("a...") << endl;
    return 0;
}
