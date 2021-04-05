#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Master {
public:
    int guess(string word) { return 6; }
};

// Minimize the worst cost, for each turn,
// guess the word which has the most similarity with other words
class Solution {
public:
    int m[6][26] = {0};
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (const auto& s : wordlist) {
            for (int i = 0; i < 6; ++i) m[i][s[i]-'a']++;
        }
        for (int t = 0; t < 10; ++t) {
            const string& s = most_common(wordlist);
            int r = master.guess(s);
            if (r == 6) break;
            wordlist = filter(wordlist, s, r);
        }
    }
    const string& most_common(const vector<string>& w) {
        int besti = 0, bests = 0;
        for (int i = 0; i < w.size(); ++i) {
            int s = 0;
            for (int j = 0; j < 6; ++j) s += m[j][w[i][j] - 'a'];
            if (s > bests) {
                bests = s;
                besti = i;
            }
        }
        return w[besti];
    }
    vector<string> filter(const vector<string>& w, const string& s, int r) {
        vector<string> nw;
        for (const string& ws : w) {
            int c = 0;
            for (int i = 0; i < 6; ++i) if (s[i] == ws[i]) ++c;
            if (c == r) nw.push_back(ws);
        }
        return nw;
    }
};


int main() {
    return 0;
}
