#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Similar to 496-NextGreaterElementI
// stack
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    stack<int> st;
    vector<int> res(n);
    for (int i = n-1; i >= 0; --i) {
      while (!st.empty() && t[i] >= t[st.top()]) st.pop();
      res[i] = st.empty() ? 0 : st.top()-i;
      st.push(i);
    }
    return res;
  }
};


int main() {
  return 0;
}
