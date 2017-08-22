#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <queue> 
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


// Solution 1 : dfs
class Solution_1 {
public:
    map<UndirectedGraphNode*, UndirectedGraphNode*> m;

    UndirectedGraphNode* dfs(UndirectedGraphNode* node) {
        if (m[node]) return m[node];
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        m[node] = newnode;
        for (auto &nbr : node->neighbors) {
            newnode->neighbors.push_back(dfs(nbr));
        }
        return newnode;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        dfs(node);
        return m[node];
    } 
};


// Solution 2 : bfs
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            if (!m.count(n)) {
                UndirectedGraphNode* newnode = new UndirectedGraphNode(n->label);
                m[n] = newnode;
            }
            for (auto &nbr : n->neighbors) {
                if (m.count(nbr))
                    m[n]->neighbors.push_back(m[nbr]);
                else {
                    UndirectedGraphNode* newnode = new UndirectedGraphNode(nbr->label);
                    m[nbr] = newnode;
                    m[n]->neighbors.push_back(newnode);
                    q.push(nbr);
                }
            }
        }
        return m[node];
    }
};

int main() {
    Solution s;
    return 0;
}
