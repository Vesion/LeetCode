#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int val;
    vector<Node *> neighbors;
    Node(int x) : val(x) {};
};

// Solution 1 : DFS
class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        unordered_map<Node*, Node*> copied;
        return dfs(node, copied);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& copied) {
        if (copied.count(node)) return copied[node];
        Node* newnode = new Node(node->val);
        copied[node] = newnode;
        for (Node* nbr : node->neighbors) {
            newnode->neighbors.push_back(dfs(nbr, copied));
        }
        return newnode;
    }
};


// Solution 2 : BFS
class Solution_2 {
public:
    Node *cloneGraph(Node *node) {
        if (!node) return node;
        unordered_map<Node*, Node*> cloned;
        cloned[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* t = q.front(); q.pop();
            for (Node* nbr : t->neighbors) {
                if (cloned.count(nbr)) {
                    cloned[t]->neighbors.push_back(cloned[nbr]);
                }
                else {
                    cloned[nbr] = new Node(nbr->val);
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

