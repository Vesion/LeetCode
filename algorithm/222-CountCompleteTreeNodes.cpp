#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL) , right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}


// Solution 0 : firstly get height, than use preorder traversal to count right diff, result = 2^height-1-diff, O(n) TLE
void dfs(TreeNode* root, int cur, int bottom, int& diff) {
    if (cur == bottom) {
        if (!root) ++diff;
        return;
    }
    dfs(root->right, cur+1, bottom, diff);
    dfs(root->left, cur+1, bottom, diff);
}

int countNodes_On(TreeNode* root) {
    if (!root) return 0;
    int result = 0, height = 0, diff = 0;
    for (TreeNode* t = root; t; t = t->left) ++height;
    result = pow(2, height) - 1;
    dfs(root, 1, height, diff);
    return result - diff;
}


// Solution 1 : O((lgn)^2), 212ms
// refer to https://leetcode.com/discuss/38930/concise-java-solutions-o-log-n-2
int height(TreeNode* root) {
    if (!root) return -1;
    return height(root->left) + 1;
}

int countNodes_Olgn2(TreeNode* root) {
    int h = height(root);
    if (h < 0) return 0;
    return height(root->right) == h-1 
        ? (1 << h) + countNodes_Olgn2(root->right) 
        : (1 << (h-1)) + countNodes_Olgn2(root->left);
}


// Solution 2 : top-down, divide-and-conquer, 328ms
int countNodes_dc(TreeNode* root) {
    if (!root) return 0;
    int lh = 0, rh = 0;
    for (TreeNode* p = root; p; p=p->left) ++lh;
    for (TreeNode* p = root; p; p=p->right) ++rh;
    if (lh == rh) return pow(2, lh) - 1;
    return countNodes_dc(root->left) + countNodes_dc(root->right) + 1;
}


// Solution 3 : binary search, the fastest, O(h^2), 72ms
// first check the right most child of the current node's left child. If this child is exist, we know that there may be more nodes on the right side of the tree. So we move the current node to it's right child. And repeat until we reach the lowest level.
int countNodes_bs(TreeNode* root) {
    if (!root) return 0;
    int height = 0;
    for (TreeNode* p = root; p; p = p->left) ++height;
    int level = height - 2;
    int count = 0;
    TreeNode* p = root;
    while (level >= 0) {
        TreeNode* left = p->left;
        for (int i = 0; i < level; ++i) left = left->right;
        if (left) {
            p = p->right;
            count += (1 << level);
        }
        else
            p = p->left;
        --level;
    }
    if (p) ++count;
    return (1 << (height-1)) - 1 + count;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(2);
    cout << countNodes_On(root) << endl;
    cout << countNodes_Olgn2(root) << endl;
    cout << countNodes_dc(root) << endl;
    cout << countNodes_bs(root) << endl;

    deleteTree(root);
    return 0;
}
