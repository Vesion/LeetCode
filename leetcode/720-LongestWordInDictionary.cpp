#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
  struct TrieNode {
    TrieNode* nexts[26];
    bool isEnd;
    TrieNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
  };

  TrieNode* root;

  void insert(string& word) {
    TrieNode* cur = root;
    for (char c : word) {
      if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
      cur = cur->nexts[c-'a'];
    }
    cur->isEnd = true;
  }

  bool query(string& word) {
    TrieNode* cur = root;
    for (char c : word) {
      cur = cur->nexts[c-'a'];
      if (!cur->isEnd) return false;
    }
    return true;
  }

public:
  string longestWord(vector<string>& words) {
    root = new TrieNode();
    for (string& w : words) insert(w);
    string res;
    for (string& w : words) {
      if (query(w) && (w.size() > res.size() || (w.size() == res.size() && w < res))) res = w;
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<string> w = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  cout << s.longestWord(w) << endl;
  return 0;
}
