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

// Solution 1 : Hash table, O(N)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> c;
        for (int num : nums) ++c[num];
        unordered_map<int, int> t;
        for (int num : nums) {
            if (c[num] <= 0) continue;
            --c[num];
            if (t[num-1] > 0) {
                --t[num-1];
                ++t[num];
            } else if (c[num+1] > 0 && c[num+2] > 0) {
                --c[num+1];
                --c[num+2];
                ++t[num+2];
            } else {
                return false;
            }
        }
        return true;
    }
};


// Solution 2 : Heap, O(NlogN)
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
