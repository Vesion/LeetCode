#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nexts[26];
        TrieNode() : isEnd(false) { fill_n(nexts, 26, nullptr); }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
        cur->isEnd = true;
    }

public:
    int m, n;
    unordered_set<string> sres;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) return {};
        root = new TrieNode();
        for (string& word : words) insert(word);

        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(board, i, j, root, "");
        vector<string> res;
        for (string s : sres) res.push_back(s);
        return res;
    }

    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* cur, string path) {
        char c = board[x][y];
        if (c == ' ' || !cur->nexts[c-'a']) return;

        cur = cur->nexts[c-'a'];
        path += c;
        if (cur->isEnd) sres.insert(path);

        board[x][y] = ' ';
        if (x-1 >= 0) dfs(board, x-1, y, cur, path);
        if (x+1 < m) dfs(board, x+1, y, cur, path);
        if (y-1 >= 0) dfs(board, x, y-1, cur, path);
        if (y+1 < n) dfs(board, x, y+1, cur, path);
        board[x][y] = c;
    }
};

int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    Solution s;
    auto result = s.findWords(board, words);
    for (auto w:result) cout << w << endl;
    return 0;
}

