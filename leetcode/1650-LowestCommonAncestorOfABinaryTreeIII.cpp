#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// hash table
class Solution0 {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> ps;
        while (p) {
            ps.insert(p);
            p = p->parent;
        }
        while (q) {
            if (ps.count(q)) return q;
            q = q->parent;
        }
        return nullptr;
    }
};

// find root firstly, then same to 236-LowestCommonAncestorOfABinaryTree
class Solution1 {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root = p;
        while (root->parent) root = root->parent;
        return dfs(root, p, q);
    }

    Node* dfs(Node* root, Node* p, Node* q) {
        if (!root) return root;
        if (root == p || root == q) return root;
        Node* left = dfs(root->left, p, q);
        Node* right = dfs(root->right, p, q);
        if (left && right) return root;
        if (left) return left;
        return right;
    }
};


// two pointer, modulus, similar to 160-IntersectionOfTwoLinkedLists
class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* a = p;
        Node* b = q;
        while (a != b) {
            a = !a ? q : a->parent;
            b = !b ? p : b->parent;
        }
        return a;
    }
};

int main() {

}
