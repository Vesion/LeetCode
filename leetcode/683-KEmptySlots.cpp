#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : Binary Indexed Tree, O(nlogn)
class Solution {
private:
  vector<int> sum;
  int n;

  void add(int i, int num) {
    for (int j = i; j <= n; j += (j&-j)) sum[j] += num;
  }

  int query(int i) {
    int res = 0;
    for (int j = i; j > 0; j -= (j&-j)) res += sum[j];
    return res;
  }

public:
  int kEmptySlots(vector<int>& flowers, int k) {
    n = flowers.size();
    sum.resize(n+1, 0);
    vector<int> b(n+1, 0);
    for (int i = 0; i < n; ++i) {
      int j = flowers[i];
      b[j] = 1;
      add(j, 1);
      if (j-k-1 >= 1 && b[j-k-1] == 1 && (query(j-1)-query(j-k-1) == 0)) return i+1;
      if (j+k+1 <= n && b[j+k+1] == 1 && (query(j+k)-query(j) == 0)) return i+1;
    }
    return -1;
  }
};


// Solution 2 : O(n)
class Solution_2 {
public:
  int kEmptySlots(vector<int>& flowers, int k) {
    int n = flowers.size();
    vector<int> day(n+1);
    for (int i = 0; i < n; ++i) day[flowers[i]] = i+1;
    int left = 1, right = 1+k+1;
    int res = INT_MAX;
    for (int i = 2; right <= n; ++i) {
      if (day[i] < day[left] || day[i] <= day[right]) {
        if (i == right) res = min(res, max(day[left], day[right]));
        left = i;
        right = i+k+1;
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};


int main() {
  return 0;
}
