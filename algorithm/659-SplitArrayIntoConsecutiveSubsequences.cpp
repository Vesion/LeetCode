#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <queue> 
using namespace std;

// Solution: Greedy
//    greedy strategy: for each number, we first see if it can be append to a previous consecutive sequence, 
//    if not, we then see if can start a new consecutive sequence, if neither, return false.

// Solution 1 : Greedy, Hash table, O(n)
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int,int> freq, pre_need;
    for (int& num : nums) freq[num]++;
    for (int& num : nums) {
      if (freq[num] == 0) continue;
      if (pre_need.count(num) && pre_need[num] > 0) {
        pre_need[num]--;
        pre_need[num+1]++;
      } else if(freq.count(num+1) && freq[num+1] > 0 && freq.count(num+2) && freq[num+2] > 0) {
        freq[num+1]--;
        freq[num+2]--;
        pre_need[num+3]++;
      } else return false;
      freq[num]--;
    }
    return true;
  }
};


// Solution 2 : Greedy, Heap
class Solution_2 {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int,vector<int>,greater<int>>> m;
    int need = 0;
    for (int& num : nums) {
      if (!m[num-1].empty()) {
        int len = m[num-1].top();
        m[num-1].pop();
        m[num].push(len+1);
        if (len+1 == 3) --need;
      } else {
        m[num].push(1);
        ++need;
      }
    }
    return need == 0;
  }
};


int main() {
  return 0;
}
