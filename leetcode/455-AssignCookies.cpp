#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int m = g.size(), n = s.size();
        for (int j = 0; i < m && j < n; ++j)
            if (g[i] <= s[j]) ++i;
        return i;
    }
};


int main() {
    Solution s;
    return 0;
}
