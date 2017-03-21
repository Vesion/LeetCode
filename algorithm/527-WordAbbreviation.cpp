#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : Trie, O(N*L)
// Firstly, I build trie for all words and get MLE :(
// Then, I build trie only for words whose shortest abbreviation conflicts with each other, and get MLE too :(
// Finally, get AC with manual GC :)
class Solution {
private:
    struct TrieNode {
        int count;
        unordered_map<char, TrieNode*> nexts;
        TrieNode() : count(0) {}
    };

    void insert(TrieNode* root, string& s) {
        TrieNode* cur = root;
        for (char& c : s) {
            if (!cur->nexts.count(c-'a')) cur->nexts[c-'a'] = new TrieNode();
            cur = cur->nexts[c-'a'];
            ++cur->count;
        }
    }

    int query(TrieNode* root, string& s) {
        int n = s.size();
        TrieNode* cur = root;
        for (int i = 0; i < n; ++i) {
            cur = cur->nexts[s[i]-'a'];
            if (cur->count == 1) return i;
        }
        return n;
    }

    void release(TrieNode* root){
        for(auto &p : root->nexts) release(p.second);
        delete root;
    }

public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> res(n);
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            string& s = dict[i];
            int len = s.size();
            if (len <= 3) res[i] = s;
            else {
                string abbr = s[0] + to_string(len-2) + s[len-1];
                m[abbr].push_back(i);
                res[i] = abbr;
            }
        }
        
        for (auto& p : m) {
            if (p.second.size() <= 1) continue;
            TrieNode* root = new TrieNode();
            for (int i : p.second) insert(root, dict[i]);
            for (int i : p.second) {
                int len = dict[i].size();
                int j = query(root, dict[i]);
                if (j >= len-3) res[i] = dict[i];
                else res[i] = dict[i].substr(0, j+1) + to_string(len-2-j) + dict[i][len-1];
            }
            release(root);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> d = { "abcdefg","abccefg","abcckkg" };
    //vector<string> d = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    auto r = s.wordsAbbreviation(d);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
