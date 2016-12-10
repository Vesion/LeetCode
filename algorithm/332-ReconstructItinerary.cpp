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


// Solution 0 : trivial DFS, backtracing, 165ms
class Solution_1 {
public:
    unordered_map<string, multiset<string>> graph;
    unordered_map<string, multiset<string>> edges; // remaining edges

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if (tickets.empty()) return {};
        for (auto& e : tickets) graph[e.first].insert(e.second);
        edges = graph;

        vector<string> path;
        path.push_back("JFK");
        dfs("JFK", path, tickets.size());
        return path;
    }

    bool dfs(string start, vector<string>& path, int count) {
        if (edges[start].empty()) {
            return count == 0;
        }
        for (string end : graph[start]) {
            auto it = edges[start].find(end);
            if (it != edges[start].end()) {
                edges[start].erase(it);
                path.push_back(end);
                if (dfs(end, path, count-1)) return true; // check if it's a dead path
                edges[start].insert(end);
                path.pop_back();
            }
        }
        return false;
    }
};


// Solution 1 : Fleury Algorithm
//
// 1.1 greedy DFS
class Solution {
public:
    unordered_map<string, multiset<string>> graph;

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        if (tickets.empty()) return {};
        for (auto& e : tickets) graph[e.first].insert(e.second);
        vector<string> res;
        dfs("JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string start, vector<string>& res) {
        while (!graph[start].empty()) {
            string nbr = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(nbr, res);
        }
        res.push_back(start);
    }
};

// 1.2 stack
class Solution_2 {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> graph;
        for (auto & p : tickets) graph[p.first].insert(p.second);

        vector<string> result;
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()) {
            auto port = dfs.top();
            if (graph[port].empty()) {
                result.push_back(port);
                dfs.pop();
            } else {
                dfs.push(*(graph[port].begin()));
                graph[port].erase(graph[port].begin());
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


int main() {
    Solution s;
    //vector<pair<string,string>> t = { { "JFK","SFO" },{ "JFK","ATL" },{ "SFO","ATL" },{ "ATL","JFK" },{ "ATL","SFO" } };
    vector<pair<string,string>> t ={ { "JFK","NRT" },{ "JFK","KUL" },{ "KUL","JFK" } };
    auto r = s.findItinerary(t);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

