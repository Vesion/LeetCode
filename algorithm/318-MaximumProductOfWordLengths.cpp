#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The key is to find an efficient method to juging where two words share any letters.
// So we use bit-manipulation, convert a word into a 32-bit integer, set character-'a' bit to 1, as a result, we can use AND to jugde.
// Because totally there are 26 letters, so a 32-bit integer is enough to represent a word.

int maxProduct(vector<string>& words) {
    if (words.empty()) return 0;
    int n = words.size();
    vector<int> bits(n);
    sort(words.begin(), words.end(), [](string& w1, string& w2) { return w1.size() > w2.size(); }); // for prune
    for (int i = 0; i < n; ++i)
        for (auto & c : words[i]) bits[i] |= (1 << (c-'a'));
    int result = 0;
    for (int i = 0; i < n-1; ++i) {
        int ni = words[i].size();
        if (int(ni*ni) < result) break; // due to sorting above, here we can prune
        for (int j = i+1; j < n; ++j) {
            int nj = words[j].size();
            if (!(bits[i] & bits[j])) result = max(result, int(ni*nj));
        }
    }
    return result;
}

int main() {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(words) << endl;
    return 0;
}
