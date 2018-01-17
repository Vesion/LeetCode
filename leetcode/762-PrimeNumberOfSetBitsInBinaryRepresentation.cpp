#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
  int countPrimeSetBits(int L, int R) {
    unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,31};
    int res = 0;
    for (int i = L; i <= R; ++i) if (primes.count(numOf1s(i))) ++res;
    return res;
  }

  int numOf1s(int num) {
    int res = 0;
    while (num) {
      num &= num-1;
      ++res;
    }
    return res;
  }
};


int main() {
  return 0;
}
