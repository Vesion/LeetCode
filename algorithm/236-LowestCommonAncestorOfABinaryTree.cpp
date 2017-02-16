#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <stack> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Solution 1 : recursive, bottom-up, O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return (left && right) ? root : (left ? left : right);
    }
};


// Solution 2 : iterative, verbos but very interesting
// First, we traverse the whole tree to find where p and q are,
// and in the procedure, we use a hash table to store each node's parent node,
// when we find p and q, we get the path from root to them, then finding the LCA becomes simple.
class Solution_2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        stack<TreeNode*> st; // preorder traversal with stack
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            if (cur->right) {
                parent[cur->right] = cur;
                st.push(cur->right);
            }
            if (cur->left) {
                parent[cur->left] = cur;
                st.push(cur->left);
            }
        }

        unordered_set<TreeNode*> pa; // store all p's ancestors, including p
        while (p) {
            pa.insert(p);
            p = parent[p];
        }
        while (!pa.count(q)) q = parent[q]; // check q's ancestors from bottom to up, the first one in pa is the LCA
        return q;
    }
};


int main() {
    return 0;
}
