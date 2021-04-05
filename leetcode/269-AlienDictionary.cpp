#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Topological sort

// BFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>> g;
        int n = words.size();
        unordered_map<char,int> ind;
        for (int i = 0; i < n; ++i) {
            const string& cur = words[i];
            for (char c : cur) ind[c] = 0;  // build dictionary for all letters
            if (i == n-1) continue;
            const string& next = words[i+1];
            for (int j = 0; j < cur.size(); ++j) {
                if (j == next.size()) return "";
                if (cur[j] != next[j]) {
                    g[cur[j]].push_back(next[j]);
                    break;
                }
            }
        }

        for (const auto& p : g) for (char c : p.second) ++ind[c];
        queue<char> q;
        for (const auto& p : ind) if (p.second == 0) q.push(p.first);
        string res;
        while (!q.empty()) {
            char t = q.front(); q.pop();
            res += t;
            if (!g.count(t)) continue;
            for (char c : g[t]) {
                if (--ind[c] == 0) q.push(c);
            }
        }
        return res.size() == ind.size() ? res : "";
    }
};


// DFS
class Solution1 {
public:
    unordered_map<char, vector<char>> g;
    int vis[26] = {};
    string res;

    string alienOrder(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            const string& cur = words[i];
            for (char c : cur) if (!g.count(c)) g[c] = {};  // build dictionary for letters
            if (i == n-1) continue;
            const string& next = words[i+1];
            for (int j = 0; j < cur.size(); ++j) {
                if (j == next.size()) return "";
                if (cur[j] == next[j]) continue;
                else {
                    g[cur[j]].push_back(next[j]);
                    break;
                }
            }
        }

        for (const auto& p : g) {
            if (vis[p.first-'a'] == 0 && !dfs(p.first)) return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char cur) {
        if (vis[cur-'a'] == 2) return true;
        vis[cur-'a'] = 1;
        for (char next : g[cur]) {
            if (vis[next-'a'] == 1 || !dfs(next)) return false;
        }
        vis[cur-'a'] = 2;
        res.push_back(cur);
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words = {"z", "z"};
    cout << s.alienOrder(words) <<endl;
    return 0;
}
