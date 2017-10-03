#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> score;
    for (string& op : ops) {
      if (op == "+") score.push_back(score[score.size()-1]+score[score.size()-2]);
      else if (op == "D") score.push_back(2*score.back());
      else if (op == "C") score.pop_back();
      else score.push_back(stoi(op));
    }
    return accumulate(score.begin(), score.end(), 0);
  }
};


int main() {
  Solution s;
  vector<string> ops = {"5", "2", "C", "D", "+"};
  cout << s.calPoints(ops) << endl;
  return 0;
}
