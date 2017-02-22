#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// Sliding Window
// similar to 438-FindAllAnagramsInAString, maintain a fixed-size window, but here we need to consider one word as a unit
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> dict;
        for (string& w : words) dict[w]++;
        int wlen = words[0].size();
        int n = s.size(), m = words.size()*wlen;

        vector<int> res;
        for (int start = 0; start < wlen; ++start) {
            unordered_map<string, int> f = dict;
            int c = words.size();
            int i = start, j = start;
            while (j+wlen <= n) {
                // extend window
                if (f[s.substr(j, wlen)]-- > 0) --c;
                j += wlen;

                // include all words in dict
                if (c == 0) res.push_back(i);

                // if size reaches m, fix the window size
                if (j-i == m) {
                    if (f[s.substr(i, wlen)]++ >= 0) ++c;
                    i += wlen;
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
