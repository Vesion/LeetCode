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
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegrees;
        for (int i = 0; i < (int)words.size(); ++i) {
            for (char&c : words[i]) indegrees[c] = 0; // construct dictionary
            if (i == 0) continue;
            for (int j = 0; j < (int)words[i-1].size(); ++j) {
                if (j == (int)words[i].size()) return ""; // for cases like ["wrtkj", "wrt]
                if (words[i-1][j] != words[i][j]) { 
                    graph[words[i-1][j]].insert(words[i][j]); 
                    break; 
                }
            }
        }
        // count indegrees after constructing graph, in case count repetitively
        for (auto& p : graph) for (char node : p.second) indegrees[node]++;

        queue<char> q;
        for (auto& p : indegrees) if(p.second == 0) q.push(p.first);
        string res;
        while (!q.empty()) {
            char t = q.front(); q.pop();
            res += t;
            for (char nbr : graph[t]) if (--indegrees[nbr] == 0) q.push(nbr);
        }
        return res.size() == indegrees.size() ? res : ""; // check cycle
    }
};

int main() {
    Solution s;
    vector<string> words = {"zx", "zy"};
    cout << s.alienOrder(words) <<endl;
    return 0;
}

