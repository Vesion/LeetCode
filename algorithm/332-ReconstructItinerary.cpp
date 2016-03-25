#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;

// Solution 1 : dfs
void dfs(unordered_map<string, multiset<string>>& graph, string node, vector<string>& result) {
    while (!graph[node].empty()) {
        string nbr = *graph[node].begin();
        graph[node].erase(graph[node].begin());
        dfs(graph, nbr, result);
    }
    result.push_back(node);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> graph;
    for (auto & p : tickets) graph[p.first].insert(p.second);
    vector<string> result;
    dfs(graph, "JFK", result);
    return vector<string>(result.rbegin(), result.rend());
}


// Solution 2 : not use dfs, rather than stack
vector<string> findItinerary_stack(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> graph;
    for (auto & p : tickets) graph[p.first].insert(p.second);

    vector<string> result;
    stack<string> dfs;
    dfs.push("JFK");
    while (!dfs.empty()) {
        auto port = dfs.top();
        if (graph[port].empty()) {
            // if no out edges, two cases:
            // 1. this node is terminal end node, so add it to result and pop it as it should, its ahead nodes are all in the stack.
            // 2. this node is a dead node, so add it first is right.
            result.push_back(port);
            dfs.pop();
        } else { // push neighbor nodes into stack, and erase them from graph
            dfs.push(*(graph[port].begin()));
            graph[port].erase(graph[port].begin());
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<pair<string, string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    auto r = findItinerary(tickets);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
