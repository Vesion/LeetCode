#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Trivial(brute-force) solution is O(n^2*k), k is the average length of all words.


// Here, we can use hash table to store all reversed words, O(n*k^2)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (words.empty()) return {};
        unordered_map<string, int> m;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string r = words[i];
            reverse(r.begin(), r.end());
            m[r] = i;
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (int)words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if (m.count(right) && m[right] != i && isPalindrome(left)) {
                    res.push_back({m[right], i});
                }
                if (m.count(left) && m[left] != i && isPalindrome(right)) {
                    res.push_back({i, m[left]});
                    if (left.empty()) res.push_back({m[left], i}); // for corner case ["a", ""]
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string& s) {
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

