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
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int res = -1, c = 0;
        int m[6][26] = {0};
        for (const string& word : wordlist) {
            for (int i = 0; i < 6; ++i) m[i][word[i]-'a']++;
        }
        while (res != 6 && !wordlist.empty() && c < 10) {
            int bests = 0, besti = 0;
            for (int i = 0; i < wordlist.size(); ++i) {
                int s = 0;
                for (int j = 0; j < 6; ++j) s += m[j][wordlist[i][j]-'a'];
                if (s > bests) bests = s, besti = i;
            }
            const string& t = wordlist[besti];
            res = master.guess(t);
            ++c;
            wordlist = filter(wordlist, t, res);
        }
        return;
    }

    vector<string> filter(const vector<string>& list, const string& t, int m) {
        vector<string> res;
        for (const string& word : list) {
            int c = 0;
            for (int i = 0; i < t.size(); ++i) {
                if (word[i] == t[i]) ++c;
            }
            if (c == m) res.push_back(word);
        }
        return res;
    }
};


int main() {
    return 0;
}
