#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    struct Node {
        bool end;
        Node* next[26];
    };
    Node* root;

    void insert(const string& w) {
        Node* cur = root;
        for (char c : w) {
            int t = c-'a';
            if (!cur->next[t]) cur->next[t] = new Node();
            cur = cur->next[t];
        }
        cur->end = true;
    }

    int m, n;
    unordered_set<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || words.empty()) return {};
        root = new Node();
        for (const string& w : words) insert(w);

        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            string path;
            dfs(board, i, j, path, root);
        }
        return vector<string>(res.begin(), res.end());
    }

    const int go[5] = {1, 0, -1, 0, 1};
    void dfs(vector<vector<char>>& board, int i, int j, string& path, Node* cur) {
        char c = board[i][j];
        if (cur->next[c-'a'] == nullptr) return;
        cur = cur->next[c-'a'];
        path += c;
        board[i][j] = ' ';
        if (cur->end) res.insert(path);
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d], nj = j+go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || board[ni][nj] == ' ') continue;
            dfs(board, ni, nj, path, cur);
        }
        path.pop_back();
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

