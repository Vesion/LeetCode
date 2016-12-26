#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// Sliding Window
// but here we need to consider one word as a unit
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        unordered_map<string, int> m;
        for (string& w : words) m[w]++;

        vector<int> res;
        int wlen = words[0].size();
        for (int i = 0; i < wlen; ++i) { // trick
            // below is same with common sliding window algorithm
            unordered_map<string, int> f;
            int start = i, count = 0;
            for (int j = i; j <= (int)s.size()-wlen; j += wlen) {
                string w = s.substr(j, wlen);
                if (m.count(w)) {
                    f[w]++;
                    count++;
                    while (f[w] > m[w]) {
                        f[s.substr(start, wlen)]--;
                        --count;
                        start += wlen;
                    }
                    if (count == (int)words.size())
                        res.push_back(start);
                } else {
                    f.clear();
                    count = 0;
                    start = j+wlen;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

