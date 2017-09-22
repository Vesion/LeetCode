#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class MagicDictionary {
private:
  unordered_map<string, char> m;

public:
  MagicDictionary() { }

  void buildDict(vector<string> dict) {
    for (string& w : dict) {
      for (char& c : w) {
        char t = c;
        c = '*';
        if (!m.count(w)) m[w] = t;
        else m[w] = 0;
        c = t;
      }
    }
  }

  bool search(string word) {
    for (char& c : word) {
      char t = c;
      c = '*';
      if (m.count(word) && (m[word] != t)) return true;
      c = t;
    }
    return false;
  }
};


int main() {
  return 0;
}
