#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void printPreorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(TreeNode* root) {
    if (root) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->val << " ";
    }
}

// Solution 0 : trivial iterative, not in-place
// 先完成前序遍历，存下结点顺序，再重新生成树，朴素算法
void flatten_trivial(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> prevs;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        auto it = s.top();
        prevs.push_back(it);
        s.pop();
        if (it->right) s.push(it->right);
        if (it->left) s.push(it->left);
    }
    for (int i = 0; i < prevs.size()-1; ++i) {
        prevs[i]->left = NULL;
        prevs[i]->right = prevs[i+1];
    }
}

// Solution 1 : recursive, O(n) time, O(lgn) space
void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);
    if (!root->left) return;

    // 三方合并,将左子树所形成的链表插入到root和root->right之间
    TreeNode* p = root->left;
    while (p->right) p = p->right;
    p->right = root->right;
    root->right = root->left;
    root->left = NULL;
}

// Solution 2 : iterative with stack, O(n) time, O(lgn) space
// solution0的改进版，一边遍历一边生成树
void flatten_it(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        auto it = s.top();
        s.pop();

        if (it->right) s.push(it->right);
        if (it->left) s.push(it->left);

        it->left = NULL;
        if (!s.empty()) it->right = s.top();
        else it->right = NULL;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    printPostorder(root);
    cout << endl;

    flatten_trivial(root);
    printPostorder(root);
    cout << endl;

    deleteTree(root);
    return 0;
}
