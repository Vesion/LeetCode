#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class WordDistance {
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            m[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        const auto& a1 = m[word1];
        const auto& a2 = m[word2];
        int res = INT_MAX;
        for (int i = 0, j = 0; i < a1.size() && j < a2.size(); ) {
            res = min(abs(a1[i]-a2[j]), res);
            if (a1[i] < a2[j]) ++i;
            else ++j;
        }
        return res;
    }
};


int main() {
    return 0;
}
