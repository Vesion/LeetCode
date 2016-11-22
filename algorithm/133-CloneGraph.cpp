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
        unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> copied;
        queue<UndirectedGraphNode*> q;
        copied[node] = new UndirectedGraphNode(node->label);
        q.push(node);
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            for (auto & nbr : n->neighbors) {
                if (copied.count(nbr)) {
                    copied[n]->neighbors.push_back(copied[nbr]);
                } else {
                    UndirectedGraphNode* newnode = new UndirectedGraphNode(nbr->label);
                    copied[nbr] = newnode;
                    copied[n]->neighbors.push_back(newnode);
                    q.push(nbr);
                }
            }
        }
        return copied[node];
    }
};

int main() {
    Solution s;
    return 0;
}

