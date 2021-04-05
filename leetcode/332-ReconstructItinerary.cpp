#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Construct Eulerian Path
// Hierholzer's Algorithm, greedy traversal

// Solution 1 : recursive
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto& p : tickets) {
            graph[p[0]].insert(p[1]);
        }
        vector<string> res;
        dfs("JFK", graph, res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string cur, unordered_map<string, multiset<string>>& graph, vector<string>& res) {
        while (!graph[cur].empty()) {
            string nbr = *graph[cur].begin();
            graph[cur].erase(graph[cur].begin());
            dfs(nbr, graph, res);
        }
        res.push_back(cur);
    }
};


// Solution 2 : iterative
// https://discuss.leetcode.com/topic/37631/c-non-recursive-o-n-time-o-n-space-solution-with-detail-explanations
class Solution_2 {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // Step 1: Store directed edges in a hash map
        unordered_map<string, multiset<string>> m;
        for (const pair<string, string> & ticket : tickets) {
            m[ticket.first].insert(ticket.second);
        }

        // Step 2: March greedily and traceback
        vector<string> march = { "JFK" }; // the storage for greedy searching
        vector<string> results; // store the final results reversely
        while (march.empty() == false) {
            string & from = march.back();
            if ((m.find(from) != m.end()) && (m[from].empty() == false)) { // march further
                multiset<string> & to = m[from];
                march.push_back(*(to.begin()));
                to.erase(to.begin());
            } else { // can not march further, trace back
                results.push_back(march.back()); // archive the last place
                march.pop_back();
            }
        }
        reverse(results.begin(), results.end()); // reverse the entries back
        return results;
    }
};


int main() {
    return 0;
}

