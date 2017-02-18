#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;


// Solution 1 : trivial backtracking
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> m;
        for (char& c : s) m[c]++;
        
        int odds = 0; char odd = 0;
        for (auto& p : m) if (p.second & 1) { odd = p.first; ++odds; }
        if (odds > 1) return {};
        
        int n = s.size();
        vector<string> res;
        dfs(0, n/2, odd, m, "", res);
        return res;
    }
    
    void dfs(int start, int n, char odd, unordered_map<char,int>& m, string path, vector<string>& res) {
        if (start == n) {
            string r = path; reverse(r.begin(), r.end());
            path = path + (odd ? string(1, odd) : "") + r;
            res.push_back(path);
        }
        for (auto& p : m) {
            if (p.second >= 2) {
                p.second -= 2;
                dfs(start+1, n, odd, m, path+p.first, res);
                p.second += 2;
            }
        }
    }
};


// Solution 2 : use std::next_permutation
class Solution_2 {
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
    return 0;
}
