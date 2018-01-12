#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://discuss.leetcode.com/topic/116280/easy-and-concise-solution-with-explanation-c-java-python
// https://discuss.leetcode.com/topic/116419/think-of-it-as-valid-parentheses
//
// sort, sort, sort!
//
class Solution {
public:
  string makeLargestSpecial(string S) {
    vector<string> ss;
    int cnt = 0, start = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
      if (S[i] == '1') ++cnt;
      else --cnt;
      if (cnt == 0) {
        ss.push_back("1" + makeLargestSpecial(S.substr(start+1, i-start-1)) + "0");
        start = i+1;
      }
    }
    sort(ss.begin(), ss.end(), greater<string>());
    string res;
    for (auto& s : ss) res += s;
    return res;
  }
};


int main() {
  Solution s;
  cout << s.makeLargestSpecial("11011000") << endl;
  cout << s.makeLargestSpecial("1101111011000000") << endl;
  return 0;
}
