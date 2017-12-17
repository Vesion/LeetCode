#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

class WordFilter {
private:
  struct TrieNode {
    vector<int> w;
    TrieNode* nexts[26];
    TrieNode() { fill_n(nexts, 26, nullptr); }
  };

  TrieNode *pr, *sr;

  void insert(TrieNode* root, string& s, int i) {
    TrieNode* cur = root;
    for (char c : s) {
      if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
      cur = cur->nexts[c-'a'];
      cur->w.push_back(i);
    }
  }

  vector<int> query(TrieNode* root, string& s) {
    TrieNode* cur = root;
    for (char c : s) {
      if (!cur->nexts[c-'a']) return {};
      cur = cur->nexts[c-'a'];
    }
    return cur->w;
  }

public:
  WordFilter(vector<string> words) {
    pr = new TrieNode(), sr = new TrieNode();
    vector<int> t(words.size());
    iota(t.begin(), t.end(), 0);
    pr->w = sr->w = t;
    for (int i = 0; i < (int)words.size(); ++i) {
      insert(pr, words[i], i);
      reverse(words[i].begin(), words[i].end());
      insert(sr, words[i], i);
    }
  }
  
  int f(string prefix, string suffix) {
    reverse(suffix.begin(), suffix.end());
    auto pv = query(pr, prefix), sv = query(sr, suffix);
    int i = pv.size()-1, j = sv.size()-1;
    while (i >= 0 && j >= 0) {
      if (pv[i] < sv[j]) --j;
      else if (pv[i] > sv[j]) --i;
      else return pv[i];
    }
    return -1;
  }
};


int main() {
  WordFilter wf({"abbbababbb","baaabbabbb","abababbaaa","abbbbbbbba","bbbaabbbaa","ababbaabaa","baaaaabbbb","babbabbabb","ababaababb","bbabbababa"});
  cout << wf.f("", "abaa") << endl;
  return 0;
}
