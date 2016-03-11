#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    TrieNode() : isEnd(false) {
        fill_n(children, 26, nullptr);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(vector<string>& words) {
        root = new TrieNode;
        for (auto & word : words)
            addWord(word);
    }

    TrieNode* getRoot() { return root; }

    void addWord(string& word) {
        TrieNode* cur = root;
        for (auto & ch : word) {
            if (!cur->children[ch-'a'])
                cur->children[ch-'a'] = new TrieNode();
            cur = cur->children[ch-'a'];
        }
        cur->isEnd = true;
    }
};

void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y, int m, int n, unordered_set<string>& r, string word) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == ' ') return; // out if bound or visit a char was visited before in this turn
    if (!root->children[board[x][y]-'a']) return; // do not match in trie
    root = root->children[board[x][y]-'a']; // if match, trie down
    word += board[x][y];
    if (root->isEnd) r.insert(word);
    char c = board[x][y];
    board[x][y] = ' ';
    dfs(board, root, x+1, y, m, n, r, word);
    dfs(board, root, x, y+1, m, n, r, word);
    dfs(board, root, x-1, y, m, n, r, word);
    dfs(board, root, x, y-1, m, n, r, word);
    board[x][y] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie* trie = new Trie(words);
    TrieNode* root = trie->getRoot();
    unordered_set<string> r;
    int m = board.size(); if (m == 0) return {};
    int n = board[0].size(); if (n == 0) return {};
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            dfs(board, root, i, j, m, n, r, "");
    vector<string> result;
    for (auto & word : r) result.push_back(word);
    return result;
}

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    auto result = findWords(board, words);
    for (auto w:result) cout << w << endl;
    return 0;
}
