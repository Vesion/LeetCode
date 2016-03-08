#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Solution 1 : use std::map to count every pattern, O(n) time, O(n) space
vector<string> findRepeatedDnaSequences_map(string s) {
    vector<string> result;
    if (s.size() < 10) return result;
    unordered_map<string, int> m;
    for (int i = 0; i <= s.size()-10; ++i) {
        string sub = s.substr(i, 10);
        if (m[sub]++ == 1) result.push_back(sub);
    }
    return result;
}


// Solution 2 : use bit manipulation
// refer to https://leetcode.com/discuss/24478/i-did-it-in-10-lines-of-c
vector<string> findRepeatedDnaSequences_bit(string s) {
    vector<string> r;
    if (s.size() < 10) return r;
    unordered_map<int, int> m;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = (t<<3) | (s[i++]&7);
    while (i < ss)
        if (m[t = (t<<3 & 0x3FFFFFFF) | (s[i++]&7)]++ == 1)
            r.push_back(s.substr(i-10, 10));
    return r;
}

int main() {
    auto result = findRepeatedDnaSequences_bit("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (auto s : result)
        cout << s << endl;
    return 0;
}
