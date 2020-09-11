#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Same as 846-HandOfStraights.cpp

// Count
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n % k) return false;
        if (k == 1) return true;

        map<int, int> m;
        for (int num : nums) m[num]++;
        for (auto& p : m) {
            const int s = p.first;
            const int sk = p.second;
            if (sk == 0) continue;
            for (int i = 0; i < k; ++i) {
                if (m[s+i] < sk) return false;
                m[s+i] -= sk;
            }
        }
        return true;
    }
};

// Sort
class Solution1 {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        const int n = nums.size();
        if (n % k) return false;
        if (k == 1) return true;

        sort(nums.begin(), nums.end());
        unordered_map<int,deque<int>> m;
        for (int num : nums) {
            const auto it = m.find(num);
            if (it != m.end()) {
                const int x = it->second.front();
                it->second.pop_front();
                if (it->second.empty()) m.erase(it);
                if (x < k-1) m[num+1].push_back(x+1);
            } else {
                m[num+1].push_back(1);
            }
        }
        return m.empty();
    }
};

int main() {
    return 0;
}
