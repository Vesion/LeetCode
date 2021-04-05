#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Brute force, O(s*m), s is the length of S, m is the size of vector
// TLE
class Solution0 {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        vector<int> p(n, 0);
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                const string& w = words[j];
                if (p[j] == w.size()) continue;
                if (w[p[j]] == s[i]) ++p[j];
                if (p[j] == w.size()) ++res;
            }
        }
        return res;
    }
};

// Take advantage of all characters are lower case
// Same worst time complexity of Solution0, but practically faster
class Solution1 {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<pair<int,int>> list[26];
        for (int i = 0; i < words.size(); ++i) {
            list[words[i][0]-'a'].push_back({i, 0});
        }

        for (char c : S) {
            auto w = list[c-'a'];
            list[c-'a'].clear();
            for (auto& p : w) {
                const int i = p.first;
                const int j = p.second;
                if (j+1 < words[i].size()) {
                    list[words[i][j+1]-'a'].push_back({i, j+1});
                }
            }
        }

        int noend = 0;
        for (int i = 0; i < 26; ++i) noend += list[i].size();
        return words.size() - noend;
    }
};

// Binary search, O(m*n*logs), n is the average length of words
// Since s.size() is huge, we'd like to optimize seraching in s.
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> p[26];
        for (int i = 0; i < s.size(); ++i) {
            p[s[i]-'a'].push_back(i);
        }

        int res = 0;
        for (const string& w : words) {
            bool f = true;
            int i = -1;
            for (char c : w) {
                const vector<int>& pos = p[c-'a'];
                auto it = upper_bound(pos.begin(), pos.end(), i);
                if (it == pos.end()) {
                    f = false;
                    break;
                }
                i = *it;
            }
            if (f) ++res;
        }
        return res;
    }
};

int main() {
    return 0;
}
