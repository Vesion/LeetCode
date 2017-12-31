#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
public:
  vector<string> ipToCIDR(string ip, int range) {
    int nip = strToNum(ip);
    vector<string> res;
    while (range > 0) {
      int cur = 1 << getZeros(nip);
      cur = min(cur, range);
      getCIDR(nip, cur, res);
      nip += cur;
      range -= cur;
    }
    return res;
  }

  void getCIDR(int nip, int range, vector<string>& res) {
    if (range <= 0) return;
    int i = 0;
    while ((1 << (i+1)) <= range) ++i;
    res.push_back(numToStr(nip) + "/" + to_string(32-i));
    int cur = 1 << i;
    getCIDR(nip+cur, range-cur, res);
  }

  int getZeros(int num) {
    int res = 0;
    while (!(num&1)) { ++res; num >>= 1; }
    return res;
  }

  int strToNum(string& sip) {
    int nip = 0;
    istringstream in(sip);
    string w;
    while (getline(in, w, '.')) nip = (nip<<8) + stoi(w);
    return nip;
  }

  string numToStr(int nip) {
    string sip;
    for (int i = 0; i < 4; ++i) {
      sip = (i == 3 ? "" : ".") + to_string(nip&255) + sip;
      nip >>= 8;
    }
    return sip;
  }
};


int main() {
  Solution s;
  auto r = s.ipToCIDR("255.0.0.32", 22);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
