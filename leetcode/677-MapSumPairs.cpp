#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class MapSum {
private:
  struct TrieNode {
    TrieNode* nexts[26];
    int val, isEnd;
    TrieNode() { val = isEnd = 0; memset(nexts, 0, sizeof nexts); }
  };

  TrieNode* root;

  void t_insert(string& key, int val) {
    TrieNode* cur = root;
    for (char& c : key) {
      if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TrieNode();
      cur = cur->nexts[c-'a'];
      cur->val += val;
    }
    cur->isEnd = true;
  }

  TrieNode* t_query(string& prefix) {
    TrieNode* cur = root;
    for (char& c : prefix) {
      if (!cur->nexts[c-'a']) return nullptr;
      cur = cur->nexts[c-'a'];
    }
    return cur;
  }

public:
  MapSum() {
    root = new TrieNode(); 
  }
  
  void insert(string key, int val) {
    TrieNode* t = t_query(key);
    t_insert(key, (t && t->isEnd) ? val-t->val : val);
  }
  
  int sum(string prefix) {
    TrieNode* t = t_query(prefix);
    return t ? t->val : 0;
  }
};


int main() {
  MapSum m;
  m.insert("apple", 3);
  cout << m.sum("ap") << endl;
  m.insert("app", 2);
  cout << m.sum("ap") << endl;
  return 0;
}
