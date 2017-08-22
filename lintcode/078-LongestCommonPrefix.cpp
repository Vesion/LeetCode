#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : scan from left to right, compare with the first one
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        for (int k = 0; k < (int)strs[0].size(); ++k) {
            for (int i = 1; i < (int)strs.size(); ++i) {
                if (strs[i][k] != strs[0][k]) return strs[0].substr(0,k);
            }
        }
        return strs[0];
    }
};


// Solution 2 : Trie, just for practising
class Solution_2 {
private:
    struct TrieNode {
        TrieNode* nexts[128];
        bool isEnd;
        TrieNode() : isEnd(false) { fill_n(nexts, 128, nullptr); }
        int hasOneNext() {
            int count = 0, one = 0;
            for (int i = 0; i < 128; ++i) {
                if (nexts[i] != nullptr) {
                    ++count; one = i;
                }
                if (count > 1) return -1;
            }
            return count == 1 ? one : -1;
        }
    };

    struct Trie {
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(string &str) {
            TrieNode* cur = root;
            for (auto &c : str) {
                if (!cur->nexts[(int)c])
                    cur->nexts[(int)c] = new TrieNode();
                cur = cur->nexts[(int)c];
            }
            cur->isEnd = true;
        }

        string getLCP() {
            string result;
            TrieNode* cur = root;
            while (!cur->isEnd) {
                int one = cur->hasOneNext();
                if (one == -1) break;
                result += (char)one;
                cur = cur->nexts[one];
            }
            return result;
        }
    };

public:    
    string longestCommonPrefix(vector<string> &strs) {
        Trie trie;
        for (auto &str : strs) trie.insert(str);
        return trie.getLCP();
    }
};

int main() {
    vector<string> strs = {"123", "1234567", "1234"};

    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

    Solution_2 s2;
    cout << s2.longestCommonPrefix(strs) << endl;
    return 0;
}
