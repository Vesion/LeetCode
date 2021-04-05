#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sort and dp, O(nlogn + nss), s for the average length of words
class Solution0 {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& w1, const string& w2) {
                 return w1.size() < w2.size();
             });
        unordered_map<string, int> m;
        int res = 1;
        for (const string& w : words) {
            m[w] = 1;
            for (int i = 0; i < w.size(); ++i) {
                const string pw = w.substr(0, i) + w.substr(i+1);
                if (m.count(pw)) m[w] = max(m[w], m[pw] + 1);
            }
            res = max(res, m[w]);
        }
        return res;
    }
};

// Top-down DP
class Solution {
public:
    unordered_map<string, int> dp;
    unordered_map<int, vector<string>> m;

    int longestStrChain(vector<string>& words) {
        for (const string& w : words) {
            m[w.size()].push_back(w);
        }
        int res = 0;
        for (const string& w : words) {
            res = max(res, dfs(w));
        }
        return res;
    }

    int dfs(const string& w) {
        if (dp.count(w)) return dp[w];
        int res = 0;
        int n = w.size();
        if (!m.count(n+1)) return 1;
        for (const string& nw : m[n+1]) {
            if (isnext(w, nw)) res = max(res, dfs(nw));
        }
        return dp[w] = res+1;
    }

    bool isnext(const string& w, const string& nw) {
        int i = 0, j = 0;
        for (; i < w.size() && j < nw.size(); ) {
            if (w[i] == nw[j]) ++i, ++j;
            else ++j;
        }
        return i == w.size();
    }
};


int main() {
}
