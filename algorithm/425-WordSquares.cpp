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
        bool isEnd;
        TrieNode() { isEnd = false, fill_n(nexts, 26, nullptr); }
    };
    
    TrieNode* root;

    void insert(string& word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (cur->nexts[c-'a'] == nullptr)
                cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
        }
        cur->isEnd = true;
    }
    
    vector<string> queryWithPrefix(string& prefix) {
        vector<string> res;
        query(prefix, 0, root, "", res);
        return res;
    }
    
    void query(string& s, int start, TrieNode* cur, string path, vector<string>& res) {
        if (!cur) return;
        if (cur->isEnd) {
            res.push_back(path);
            return;
        }
        if (start < (int)s.size()) {
            char c = s[start];
            if (cur->nexts[c-'a'] == nullptr) return;
            query(s, start+1, cur->nexts[c-'a'], path+c, res);
        } else {
            for (int i = 0; i < 26; ++i) {
                if (cur->nexts[i] != nullptr)
                    query(s, start+1, cur->nexts[i], path+string(1, 'a'+i), res);
            }
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return {};

        root = new TrieNode();
        for (string& word: words) insert(word);
        
        vector<vector<string>> res;
        for (string& word : words) { // try every word as first row
            vector<string> path({word});
            dfs(word, 1, path, res);
        }
        return res;
    }
    
    void dfs(string& s, int start, vector<string>& path, vector<vector<string>>& res) {
        if (start == (int)s.size()) {
            res.push_back(path);
            return;
        }

        string prefix;
        for (string& word : path) prefix += word[start];
        auto r = queryWithPrefix(prefix);
        if (r.empty()) return;

        for (string& word : r) {
            path.push_back(word);
            dfs(s, start+1, path, res);
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

