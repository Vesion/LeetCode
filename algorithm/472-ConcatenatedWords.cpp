#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;


// Solution 1 : Trie + DFS, get MLE for the last test case
class Solution_1 {
private:
    struct TrieNode {
        bool isEnd;
        TrieNode* nexts[26];
        TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c-'a';
            if (!cur->nexts[i]) cur->nexts[i] = new TrieNode();
            cur = cur->nexts[i];
        }
        cur->isEnd = true;
    }

    bool concatenate(string& word, int start, TrieNode* cur, int num) {
        if (start == (int)word.size()) return cur == root && num > 1;
        char c = word[start];
        if (cur->nexts[c-'a']) {
            if (cur->nexts[c-'a']->isEnd && concatenate(word, start+1, root, num+1)) return true; 
            if (concatenate(word, start+1, cur->nexts[c-'a'], num)) return true;
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty()) return {};
        root = new TrieNode();
        for (string& w : words) insert(w);

        vector<string> res;
        for (string& w : words) 
            if (concatenate(w, 0, root, 0)) res.push_back(w);
        return res;
    }
};


// Solution 2 : dp, similar to 139-WordBreak
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string s1, const string s2) { return s1.size() < s2.size(); }); // sort with length
        unordered_set<string> dict;
        vector<string> res;
        for (string& w : words) {
            if (canBreak(w, dict)) res.push_back(w); // words in dict are shorter than current one
            dict.insert(w);
        }
        return res;
    }
    
    bool canBreak(string& word, unordered_set<string>& dict) {
        if (word.empty() || dict.empty()) return false;
        int n = word.size();
        vector<bool> dp(n+1, false); // dp[i] means word[0:i) can be broken
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.count(word.substr(j, i-j))) {
                    dp[i] = true;
                    break; // we only care about if it can be broken, so we can stop here
                }
            }
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    //vector<string> words = {"a", "b", "ab", "abc"};
    auto r = s.findAllConcatenatedWordsInADict(words);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
