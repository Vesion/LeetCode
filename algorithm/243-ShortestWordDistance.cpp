#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        int i1 = -1, i2 = -1;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (words[i] == word1) i1 = i;
            else if (words[i] == word2) i2 = i;
            if (i1 != -1 && i2 != -1) res = min(res, abs(i1-i2));
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
