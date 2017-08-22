#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.empty()) return 0;
        unordered_set<int> unused(num.begin(), num.end());
        int result = 0;
        for (auto &n : num) {
            if (!unused.count(n)) continue;
            int l = n-1, r = n+1;
            while (unused.count(l)) unused.erase(l--);
            while (unused.count(r)) unused.erase(r++);
            result = max(result, r-l-1);
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
