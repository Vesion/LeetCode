#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        int i1 = -1, i2 = -1;
        bool e = word1 == word2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                if (e) { i1 = i2; i2 = i; } 
                else i1 = i;
            }
            else if (words[i] == word2) i2 = i;
            if (i1 != -1 && i2 != -1) res = min(res, abs(i2-i1));
        }
        return res;
    }
};

int main() {
    return 0;
}
