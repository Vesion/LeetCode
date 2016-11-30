#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX;
        auto ids1 = m[word1], ids2 = m[word2];
        int i = 0, j = 0;
        while (i < ids1.size() && j < ids2.size()) { // ids1 and ids2 are sorted, so we use the idea of merge sort, O(m+n)
            res = min(res, abs(ids1[i]-ids2[j]));
            if (ids1[i] > ids2[j]) ++j;
            else ++i;
        }
        return res;
    }
};


int main() {
    return 0;
}
