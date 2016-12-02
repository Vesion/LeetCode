#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        
        int odd = 0; string oddc;
        string half;
        for (int i = 0; i < 128; ++i) {
            if (m[i]%2) { ++odd; oddc = i; }
            half += string(m[i]/2, i);
        }
        if (odd > 1) return {};
        
        vector<string> res;
        do {
            string r = half;
            reverse(r.begin(), r.end());
            res.push_back(half + (odd ? oddc : "") + r);
        } while (next_permutation(half.begin(), half.end()));
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
