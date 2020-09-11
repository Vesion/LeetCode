#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int c = 0;
        for (const string& word : words) {
            if (issubseq(S, word)) ++c;
        }
        return c;
    }

    bool issubseq(const string& s, const string& w) {
        int i = 0, j = 0;
        while (i < s.size() && j < w.size()) {
            int cs = 1, cw = 1;
            char ds = s[i], dw = w[j];
            while (i+1 < s.size() && s[i] == s[i+1]) { ++cs; i++; }
            while (j+1 < w.size() && w[j] == w[j+1]) { ++cw; j++; }
            if (ds == dw && cs >= cw && (cs == cw || cs >= 3)) { ++i; ++j; }
            else return false;
        }
        return i == s.size() && j == w.size();
    }
};


int main() {
    return 0;
}
