#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// common bitmap, O(nk + n^2), k is average length of all words
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty()) return 0;
        int n = words.size();
        vector<int> m(n, 0);
        for (int i = 0; i < n; ++i) {
            for (char& c : words[i]) {
                m[i] |= (1 << (c-'a'));
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((m[i]&m[j]) != 0) continue; // this two have common letters
                res = max(res, (int)words[i].size()*(int)words[j].size());
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
