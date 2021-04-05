#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Trivial(brute-force) solution is O(n^2*k), k is the average length of all words.


// We can use hash table to store all reversed words, O(n*k^2)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string rw = words[i];
            reverse(rw.begin(), rw.end());
            m[rw] = i;
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            const string& w = words[i];
            for (int j = 0; j < w.size(); ++j) {
                string left = w.substr(0, j);  // could be empty
                string right = w.substr(j);
                if (m.count(left) && m[left] != i && ispalindrome(right)) {
                    res.push_back({i, m[left]});
                    if (left.empty()) res.push_back({m[left], i});  // ["a", ""]
                }
                if (m.count(right) && m[right] != i && ispalindrome(left)) {
                    res.push_back({m[right], i});
                }
            }
        }
        return res;
    }

    bool ispalindrome(const string& s) {
        if (s.empty()) return true;
        int i = 0, j = s.size()-1;
        while (i <= j && s[i] == s[j]) ++i, --j;
        return i > j;
    }
};


int main() {
    Solution s;
    vector<string> w = {"a", ""};
    auto r = s.palindromePairs(w);
    for (auto& e : r) cout << e[0] << " " << e[1] <<endl;; cout << endl;
    return 0;
}

