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
            string w = words[i];
            reverse(w.begin(), w.end()); 
            m[w] = i;
        }

        vector<vector<int>> res;
        if (m.count("")) { // edge case
            for (int i = 0; i < n; ++i) {
                if (isPalindrome(words[i]) && m[""] != i) res.push_back({m[""], i});
            }
        }

        for (int i = 0; i < n; ++i) {
            int len = words[i].size();
            for (int l = 0; l < len; ++l) { // split word into left(0 ~ n-1) and right(n ~ 1) part
                string left = words[i].substr(0, l);
                string right = words[i].substr(l);
                if (m.count(left) && isPalindrome(right) && m[left] != i)
                    res.push_back({i, m[left]});
                if (m.count(right) && isPalindrome(left) && m[right] != i)
                    res.push_back({m[right], i});
            }
        }
        return res;
        
    }

    bool isPalindrome(string& s) {
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

