#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
private:
  struct TireNode {
    bool isEnd;
    TireNode* nexts[26];
    TireNode() { isEnd = false; fill_n(nexts, 26, nullptr); }
  };

  TireNode* root;

  void insert(string& s) {
    TireNode* cur = root;
    for (char& c : s) {
      if (!cur->nexts[c-'a']) cur->nexts[c-'a'] = new TireNode();
      cur = cur->nexts[c-'a'];
    }
    cur->isEnd = true;
  }

  string query(string& s) {
    TireNode* cur = root;
    string res;
    for (char& c : s) {
      if (cur->nexts[c-'a']) {
        cur = cur->nexts[c-'a'];
        res += c;
      } else break;
      if (cur->isEnd) return res;
    }
    return s;
  }

public:
  string replaceWords(vector<string>& dict, string sentence) {
    root = new TireNode();
    for (string& s : dict) insert(s);
    istringstream in(sentence);
    string word, res;
    while (in >> word) res += query(word) + " ";
    res.pop_back();
    return res;
  }
};

int main() {
  Solution s;
  vector<string> d = {"cat", "bat", "rat"};
  cout << s.replaceWords(d, "the cattle was rattled by the battery") << endl;
  return 0;
}
