#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

// Solution 1 : BFS
UndirectedGraphNode *cloneGraph_bfs(UndirectedGraphNode *node) {
    if (!node) return node;

    unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> copied; // key is original node, value is the node has been copied
    queue<UndirectedGraphNode*> q; // bfs queue, each node in the queue has been copied, but its neighbors are not been copied yet
    copied[node] = new UndirectedGraphNode(node->label);
    q.push(node);
    while (!q.empty()) {
        auto n = q.front(); q.pop();
        for (auto & nbr : n->neighbors) {
            if (copied.find(nbr) != copied.end()) {
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

// Solution 2 : dfs
UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& copied) {
    if (copied.find(node) != copied.end()) return copied[node];
    UndirectedGraphNode* newnode = new UndirectedGraphNode(node->label);
    copied[node] = newnode;
    for (auto & nbr : node->neighbors)
        newnode->neighbors.push_back(clone(nbr, copied));
    return newnode;
}

UndirectedGraphNode *cloneGraph_dfs(UndirectedGraphNode *node) {
    if (!node) return node;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
    clone(node, copied);
    return copied[node];
}

int main() {
    UndirectedGraphNode* n0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* n1 = new UndirectedGraphNode(2);
    UndirectedGraphNode* n2 = new UndirectedGraphNode(2);
    n0->neighbors.push_back(n1);
    n0->neighbors.push_back(n2);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n2);

    auto clone = cloneGraph_bfs(n0);
    auto clone2 = cloneGraph_dfs(n0);
    
    delete n0;
    delete n1;
    delete n2;
    return 0;
}
