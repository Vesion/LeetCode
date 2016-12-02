#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <queue> 
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        int n = words.size();

        unordered_set<char> dict({words[0].begin(), words[0].end()});
        unordered_map<char, unordered_set<char>> graph;
        for (int i = 1; i < n; ++i) {
            dict.insert(words[i].begin(), words[i].end());
            int l1 = words[i-1].size(), l2 = words[i].size();
            int j = 0, k = 0;
            while (j < l1 && k < l2) {
                if (words[i-1][j] != words[i][k]) {
                    graph[words[i-1][j]].insert(words[i][k]);
                    break;
                }
                ++j; ++k;
            }
            if (j < l1 && k == l2) return "";
        }

        unordered_map<char, int> indegrees;
        for (auto& p : graph) {
            for (char c : p.second) {
                if (c != p.first) indegrees[c]++;
            }
        }

        queue<char> q;
        for (char c : dict) if (indegrees[c] == 0) q.push(c);
        if (q.empty()) return "";

        string res;
        while (!q.empty()) {
            char t = q.front(); q.pop();
            res += t;
            for (char nbr : graph[t]) {
                if (--indegrees[nbr] == 0) q.push(nbr);
            }
        }
        return res.size() == dict.size() ? res : "";
    }
};

int main() {
    Solution s;
    //vector<string> w = { "wrt", "wrf", "er", "ett", "rftt" };
    vector<string> w = {"wrtkj"};
    cout << s.alienOrder(w) << endl;
    return 0;
}
