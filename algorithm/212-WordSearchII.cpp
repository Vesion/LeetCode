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
    int m, n;
    int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty()) return {};
        root = new TrieNode();
        for (string& w : words) insert(w);
        
        m = board.size(), n = board[0].size();
        unordered_set<string> res;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dfs(board, i, j, root, "", res);
        return vector<string>(res.begin(), res.end());
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* cur, string path, unordered_set<string>& res) {
        char c = board[i][j];
        if (!cur->nexts[c-'a']) return;
        cur = cur->nexts[c-'a'];
        path += c;
        if (cur->isEnd) res.insert(path);
        board[i][j] = ' '; // flag visited
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] == ' ') continue;
            dfs(board, ni, nj, cur, path, res);
        }
        board[i][j] = c;
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
    auto r = s.findWords(board, words);
    for (auto w:r) cout << w << endl;
    return 0;
}

