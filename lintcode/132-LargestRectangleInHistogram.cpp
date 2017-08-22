#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Node {
public:
    Node* next[26];
    bool isEnd;
    Node() : isEnd(false) {
        fill(next, next+26, nullptr);
    }
};

class Trie {
public:
    Node* root;

    Trie() { root = new Node(); }
    
    void insert(string s) {
        auto n = root;
        for (char& c : s) {
            if (!n->next[c-'a'])
                n->next[c-'a'] = new Node();
            n = n->next[c-'a'];
        }
        n->isEnd = true;
    }

    bool search(string s) {
        auto n = root;
        for (auto &c : s) {
            if (!n->next[c-'a']) return false;
            n = n->next[c-'a'];
        }
        return n->isEnd == true;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, int m, int n, int x, int y, Node* root, set<string>& result, string path) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] == ' ') return;
        if (!root->next[board[x][y]-'a']) return;
        root = root->next[board[x][y]-'a'];
        path += board[x][y];
        if (root->isEnd) result.insert(path);
        char old = board[x][y];
        board[x][y] = ' ';
        dfs(board, m, n, x+1, y, root, result, path);
        dfs(board, m, n, x, y+1, root, result, path);
        dfs(board, m, n, x-1, y, root, result, path);
        dfs(board, m, n, x, y-1, root, result, path);
        board[x][y] = old;
    }

    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        if (board.empty() || words.empty()) return {};
        int m = board.size(), n = board[0].size();
        Trie trie;
        for (auto &s : words) trie.insert(s);
        Node* root = trie.root;

        set<string> result;
        
        for(int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, m, n, i, j, root, result, "");
            }
        }

        return {result.begin(), result.end()};
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'a', 'd'},
        {'c', 'e'},
    };
    vector<string> words = {"adec"};
    auto r = s.wordSearchII(board, words);
    for (auto i : r) cout << i << endl;
    return 0;
}
