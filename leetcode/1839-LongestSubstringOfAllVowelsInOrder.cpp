#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int res = 0;
        int n = word.size();
        int m[26] = {};
        int v = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            char c = word[i];
            if (++m[c-'a'] == 1) ++v;
            if (i > 0 && word[i] < word[i-1]) {
                while (j < i) if (--m[word[j++]-'a'] == 0) --v;
            }
            if (v == 5) res = max(res, i-j+1);
        }
        return res;
    }
};

int main() {

}