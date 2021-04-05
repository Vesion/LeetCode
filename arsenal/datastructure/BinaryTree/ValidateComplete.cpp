#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Given a binary tree, check whether it is a complete binary tree or not.
// A complete binary tree is a binary tree in which every level,
// except possibly the last, is completely filled, and all nodes are as far left as possible.


// Solution 1 : iterative, level traversal, O(n) time, O(n) space
// If a node have neither left child or right child, all the following nodes must be leaf nodes.
class Solution_1 {
public:
    bool isComplete(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool leaf = false;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur->left) {
                if (leaf) return false;
                q.push(cur->left);
            } else leaf = true;
            if (cur->right) {
                if (leaf) return false;
                q.push(cur->right);
            } else leaf = true;
        }
        return true;
    }
};


// Solution 2 : recursive, count and index, O(n) time, O(1) space
// A complete tree's nodes can be consecutively indexed (this is why we can use an array to represent a complete tree)
// if a node's index is i, it's left child is 2*i+1, right child is 2*i+2
// first we count the number of nodes, then check if all nodes' index is smaller than count
// Pigeonhole Principle
class Solution_2 {
public:
    bool isComplete(TreeNode* root) {
        return isComplete(root, 1, count(root));
    }

    int count(TreeNode* root) {
        return root ? count(root->left) + count(root->right) + 1 : 0;
    }

    bool isComplete(TreeNode* root, int index, int count) {
        if (!root) return true;
        return index <= count && isComplete(root->left, 2*index, count) && isComplete(root->right, 2*index+1, count);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(2);
    //root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(2);

    Solution_1 s1;
    cout << s1.isComplete(root) << endl;

    Solution_2 s2;
    cout << s2.isComplete(root) << endl;
    return 0;
}
