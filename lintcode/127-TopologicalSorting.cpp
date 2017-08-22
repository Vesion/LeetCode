#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <queue> 
using namespace std;

struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};


// Solution 1 : bfs
class Solution_1 {
public:

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        if (graph.empty()) return {};

        map<DirectedGraphNode*, int> indegrees;
        for (auto &n : graph) {
            for (auto &nbr : n->neighbors)
                ++indegrees[nbr];
        }

        queue<DirectedGraphNode*> q;
        for (auto &p : graph) {
            if (indegrees[p] == 0) q.push(p);
        }

        vector<DirectedGraphNode*> result;
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            result.push_back(n);
            for (auto &nbr : n->neighbors) {
                if (--indegrees[nbr] == 0)
                    q.push(nbr);
            }
        }

        return result;
    }    
};


// Solution 2 : dfs
class Solution {
public:
    map<DirectedGraphNode*, bool> visited;
    map<DirectedGraphNode*, bool> onpath; // to detect cycle
    vector<DirectedGraphNode*> result;

    bool dfs(DirectedGraphNode* cur) {
        if (visited[cur]) return false;
        visited[cur] = onpath[cur] = true;
        for (auto &nbr : cur->neighbors) {
            if (onpath[nbr] || dfs(nbr)) return true;
        }
        onpath[cur] = false;
        result.push_back(cur);
        return false;
    }

    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        if (graph.empty()) return {};
        for (auto &n : graph) {
            if (dfs(n)) return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }    
};

int main() {
    Solution s;

    DirectedGraphNode* n1 = new DirectedGraphNode(1);
    DirectedGraphNode* n2 = new DirectedGraphNode(2);
    DirectedGraphNode* n3 = new DirectedGraphNode(3);
    DirectedGraphNode* n4 = new DirectedGraphNode(4);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n4);
    //n4->neighbors.push_back(n1);
    auto r = s.topSort({n1, n2, n3, n4});
    for (auto i : r)
        cout << i->label <<endl;
    return 0;
}
