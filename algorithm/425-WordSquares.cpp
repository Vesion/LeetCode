#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* nexts[26];
        TrieNode() { fill_n(nexts, 26, nullptr); }
    };
    TrieNode* root;

    void insert(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
    }

    vector<string> query(string s) {
        vector<string> res;
        string path;
        query(s, 0, root, res, path);
        return res;
    }

    // find all paths in the trie which prefixed with s
    void query(string& s, int start, TrieNode* cur, vector<string>& res, string& path) {
        if (start == n) {
            res.push_back(path);
            return;
        }
        if (start < (int)s.size()) {
            if (!cur->nexts[s[start]-'a']) return;
            else {
                path.push_back(s[start]);
                query(s, start+1, cur->nexts[s[start]-'a'], res, path);
            }
        } else {
            for (int i = 0; i < 26; ++i) {
                if (cur->nexts[i]) {
                    path.push_back(i+'a');
                    query(s, start+1, cur->nexts[i], res, path);
                    path.pop_back();
                }
            }
        }
    }

public:
    vector<vector<string>> res;
    vector<string> path;
    int n;

    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].size();
        root = new TrieNode();
        for (string& w : words) insert(w);

        for (string& start : words) { // try every word for the first row
            path.push_back(start);
            dfs(1, start);
            path.clear();
        }
        return res;
    }

    void dfs(int row, string& start) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        string prefix;
        for (int i = 0; i < row; ++i) prefix += path[i][row];
        auto words = query(prefix); // find all words with this prefix
        if (words.empty()) return; // if no such words, terminate this search path

        for (string& w : words) {
            path.push_back(w);
            dfs(row+1, start);
            path.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<string> words = {"area","lead","wall","lady","ball"};
    auto r = s.wordSquares(words);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

