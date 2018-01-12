#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
  vector<int> anagramMappings(vector<int>& A, vector<int>& B) { 
    int n = A.size();
    vector<int> res(n);
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) m[B[i]].push_back(i);
    for (int i = 0; i < n; ++i) {
      res[i] = m[A[i]].back();
      m[A[i]].pop_back();
    }
    return res;
  }
};


int main() {
  return 0;
}
