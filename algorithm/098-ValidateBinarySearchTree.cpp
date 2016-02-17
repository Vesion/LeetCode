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

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

// Solution 1 : Min-Max range, O(n) time, O(1) space
// we use the min-val and max-val to record the range scope of the root-left-sub-tree and root-right-sub-tree
bool isValid(TreeNode* node, long leftMin, long rightMax) {
    if (!node) return true;
    return ((node->val > leftMin && node->val < rightMax)
            && isValid(node->left, leftMin, node->val) 
            && isValid(node->right, node->val, rightMax));
}
bool isValidBST_range(TreeNode* root) {
    // use long int in case of overflow
    return isValid(root, LONG_MIN, LONG_MAX);
}


// Solution 2 : inorder traversal, O(n) time, O(1) space
// refer to https://leetcode.com/discuss/81672/recommend-beginners-implementation-detailed-explaination
// 利用二叉搜索树的中序遍历结果是严格升序的特性，使用094-BinaryTreeInorderTraversal中迭代遍历的方法得到中序遍历，检查是否是严格升序
bool isValidBST_inorder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* it = root;
    long last = LONG_MIN; // use long in case of overflow
    while (it || !s.empty()) {
        if (it) {
            s.push(it);
            it = it->left;
        } else {
            it = s.top();
            s.pop();
            if (last >= it->val) return false;
            last = it->val;
            it = it->right;
        }
    } 
    return true;
}

int main() {
    TreeNode* root = new TreeNode(INT_MIN);
    //root->left = new TreeNode(INT_MAX);
    //root->right = new TreeNode(15);
    //root->right->right = new TreeNode(20);
    //root->right->left = new TreeNode(11);
    printInorder(root);
    cout << endl;

    cout << isValidBST_range(root);
    cout << isValidBST_inorder(root);
    deleteTree(root);
    return 0;
}
