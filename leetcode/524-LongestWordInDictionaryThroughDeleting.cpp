#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int maxc = 0;
        string res;
        for (const string& w : dictionary) {
            if (subseq(s, w)) {
                if (w.size() > maxc || (w.size() == maxc && w < res)) {
                    maxc = w.size();
                    res = w;
                }
            }
        }
        return res;
    }

    bool subseq(const string& s, const string& w) {
        int i = 0;
        for (char c : s) {
            if (i == w.size()) break;
            if (c == w[i]) ++i;
        }
        return i == w.size();
    }
};


int main() {
    return 0;
}
