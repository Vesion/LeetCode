#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

TreeNode* insertNode(TreeNode* root, int x) {
    if (!root)
        root = new TreeNode(x);
    else {
        if (x < root->val)
            root->left = insertNode(root->left, x);
        else
            root->right = insertNode(root->right, x);
    }
    return root;
}

void printPreorder(TreeNode* &root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Solution 0 : not in-place, use O(n) place
// cannot work in leetcode, due to different function signature (we use reference parameter)
void recoverPreorder(TreeNode* &root, TreeNode* &newRoot) {
    if (root) {
        newRoot = insertNode(newRoot, root->val);
        recoverPreorder(root->left, newRoot);
        recoverPreorder(root->right, newRoot);
    }
}
void recoverTree_no(TreeNode* &root) {
    TreeNode* newRoot = NULL;
    recoverPreorder(root, newRoot);
    root = newRoot;
}

// Solutions : inorder traversal
// 该题的核心思路就是利用二叉搜索树的中序遍历是严格升序这一特性，在中序遍历的过程中找到两个非升序结点，最后交换他们的值即可
// 所以解法就跟中序遍历一样分三种：recursive, iterative with stack, Morris traversal
// refer to https://leetcode.com/discuss/68639/solutions-explanation-recursive-iterative-traversal-traversal

// Solution 1 : inorder traversal recursively, O(n) place
TreeNode* previous = NULL;
TreeNode *first = NULL, *second = NULL;
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    if (previous && previous->val >= root->val) {
        if (first == NULL) first = previous;
        second = root;
    }
    previous = root;
    inorder(root->right);
}
void recoverTree_re(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
}

// Solution 2 : inorder traversal with stack, O(n) place
void recoverTree_itstack(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode *n1 = NULL, *n2 = NULL;
    TreeNode dummy(INT_MIN);
    TreeNode* last = &dummy;
    TreeNode* it = root;
    while (it || !s.empty()) {
        if (it) {
            s.push(it);
            it = it->left;
        } else {
            it = s.top();
            s.pop();
            if (it->val <= last->val) {
                if (!n1) n1 = last; // incorrect smaller node is always found as prev node
                n2 = it; //incorrect larger node is always found as curr(root) node
            }
            last = it;
            it = it->right;
        }
    }
    swap(n1->val, n2->val);
}

// Solution 3 : Morris traversal, O(1) place
// do not implement here


int main() {
    TreeNode* root = NULL;
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    root->left->left->left = new TreeNode(10);
    root->right->right->right = new TreeNode(2);
    printPreorder(root);
    cout << endl;

    //recoverTree_itstack(root);
    recoverTree_re(root);
    printPreorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
