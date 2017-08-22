#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    int r = 0, d = 0;
    queue<char> q;
    for (char& c : senate) {
      c == 'R' ? ++r : ++d;
      q.push(c);
    }
    int br = 0, bd = 0;
    while (!q.empty() && r && d) {
      char t = q.front(); q.pop();
      if (t == 'R') {
        if (bd) { --bd; --r; }
        else { ++br; q.push(t); }
      } else {
        if (br) { --br; --d; }
        else { ++bd; q.push(t); }
      }
    }
    return r ? "Radiant" : "Dire";
  }
};


int main() {
  Solution s;
  cout << s.predictPartyVictory("RD") << endl;
  cout << s.predictPartyVictory("RDD") << endl;
  cout << s.predictPartyVictory("DDRRR") << endl;
  cout << s.predictPartyVictory("RRDDD") << endl;
  return 0;
}
