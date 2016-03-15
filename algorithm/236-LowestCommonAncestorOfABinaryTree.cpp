#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}


// Solution 1 : firstly use dfs find the pathes from root to p and q, then find the LCA in this two pathes
void dfs(TreeNode* root, TreeNode* p, vector<TreeNode*>& path, vector<TreeNode*>& result) {
    if (root == p) { result = path; return; }
    if (root->left) { path.push_back(root->left); dfs(root->left, p, path, result); path.pop_back(); }
    if (root->right) { path.push_back(root->right); dfs(root->right, p, path, result); path.pop_back(); }
}

TreeNode* lowestCommonAncestor_path(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathp, pathq;
    vector<TreeNode*> rpathp, rpathq;
    pathp.push_back(root); pathq.push_back(root);
    dfs(root, p, pathp, rpathp); dfs(root, q, pathq, rpathq);
    int i;
    for (i = 0; i < rpathp.size() && i < rpathq.size(); ++i) {
        if (rpathp[i] != rpathq[i]) break;
    } 
    return rpathp[i-1];
}


// Solution 2 : recursive, very skillful, orz
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q); // if left is NULL, neither q or q in left; else left is p or q
    TreeNode* right = lowestCommonAncestor(root->right, p, q); // ditto
    return (left && right) ? root : (left ? left : right); // if left and right are not NULL, one if them is p, the other is q, so root is LCA; otherwise, one of them is LCA.
}


int main() {
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(2);
    TreeNode* n5 = new TreeNode(0);
    TreeNode* n6 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(4);
    root->left = n1; root->right = n2;
    n1->left = n3; n1->right = n4;
    n2->left = n5; n2->right = n6;
    n4->left = n7; n4->right = n8;

    printInorder(root);
    cout << endl;

    cout << lowestCommonAncestor(root, n4, n8)->val;

    deleteTree(root);
    return 0;
}

