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

// DFS + memo, O(nns)
class Solution {
public:
    unordered_map<string, int> m;
    unordered_map<int, vector<string>> twords;

    int longestStrChain(vector<string>& words) {
        int res = 0;
        for (const string& word : words) {
            twords[word.size()].push_back(word);
        }
        for (const string& word : words) {
            res = max(res, dfs(word));
        }
        return res;
    }

    int dfs(const string& w) {
        if (m[w]) return m[w];
        int res = 1;
        if (!twords.count(w.size()+1)) return res;
        for (const string& nw : twords[w.size()+1]) {
            if (isnext(w, nw)) res = max(res, dfs(nw) + 1);
        }
        return res;
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
