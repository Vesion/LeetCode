#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

class Solution {
public:
  int kthGrammar(int N, int K) {
    if (N == 1 || K == 1) return 0;
    int t = 1<<(N-2);
    return K > t ? (1-kthGrammar(N-1, K-t)) : kthGrammar(N-1, K);
  }
};


int main() {
  Solution s;
  for (int i = 1; i <= 16; ++i) cout << s.kthGrammar(5,i);
  return 0;
}
