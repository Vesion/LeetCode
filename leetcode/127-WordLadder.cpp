#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// One-end BFS
class Solution0 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(), wordList.end());
        if (!m.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string t = q.front(); q.pop();
                if (t == endWord) return res;
                for (int i = 0; i < t.size(); ++i) {
                    char oc = t[i];
                    for (int c = 'a'; c <= 'z'; ++c) {
                        if (c == oc) continue;
                        t[i] = c;
                        if (m.count(t)) {
                            q.push(t);
                            m.erase(t);
                        }
                        t[i] = oc;
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};

// Two-ends BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> m(wordList.begin(), wordList.end());
        if (!m.count(endWord)) return 0;

        unordered_set<string> s1({beginWord}), s2({endWord});
        int res = 1;
        while (!s1.empty() && !s2.empty()) {
            auto& t1 = s1.size() < s2.size() ? s1 : s2;
            auto& t2 = s1.size() < s2.size() ? s2 : s1;
            unordered_set<string> t;
            ++res;
            for (const string& s : t1) {
                string w = s;
                for (int i = 0; i < s.size(); ++i) {
                    char oc = s[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == oc) continue;
                        w[i] = c;
                        if (t2.count(w)) return res;
                        if (m.count(w)) {
                            t.insert(w);
                            m.erase(w);
                        }
                        w[i] = oc;
                    }
                }
            }
            t1.swap(t);
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<string> list = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", list) << endl;
    return 0;
}

