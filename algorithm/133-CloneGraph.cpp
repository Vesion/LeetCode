#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <queue> 
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// Solution 1 : DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
        return dfs(node, copied);
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& copied) {
        if (copied.count(node)) return copied[node];
        UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
        copied[node] = newnode;
        for (UndirectedGraphNode* nbr : node->neighbors) {
            newnode->neighbors.push_back(dfs(nbr, copied));
        }
        return newnode;
    }
};


// Solution 2 : BFS
class Solution_2 {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloned;
        cloned[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* t = q.front(); q.pop();
            for (UndirectedGraphNode* nbr : t->neighbors) {
                if (cloned.count(nbr)) {
                    cloned[t]->neighbors.push_back(cloned[nbr]);
                }
                else {
                    cloned[nbr] = new UndirectedGraphNode(nbr->label);
                    cloned[t]->neighbors.push_back(cloned[nbr]);
                    q.push(nbr);
                }
            }
        }
        return cloned[node];
    }
};


int main() {
    return 0;
}

