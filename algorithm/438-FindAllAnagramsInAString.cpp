#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Sliding window / Two pointers
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> table(128, 0);
        for (char& c : p) table[c]++;
        int counter = p.size(), start = 0, end = 0;
        vector<int> result;
        while (end < (int)s.size()) {
            if (table[s[end++]]-- > 0) counter--; // extend
            if (counter == 0) result.push_back(start); // find a valid substring
            if (end-start == (int)p.size() && table[s[start++]]++ >= 0) counter++; // shrink
        }
        return result;
    }
};

int main() {
    Solution s;
    auto r = s.findAnagrams("abacbabc", "abc");
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
