#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// wrong!
int minDepth_w(TreeNode* root) {
    if (!root) return 0;
    return min(minDepth_w(root->left), minDepth_w(root->right)) + 1;
}

// 最小深度是指从根结点到某一叶结点的距离，所以上面的方法计算的是根结点到某一不满结点的距离，是错的
int depth(TreeNode* root, bool hasbrother) {
    if (!root) return hasbrother ? INT_MAX : 0;
    return min(depth(root->left, root->right != NULL), depth(root->right, root->left != NULL)) + 1;
}

int minDepth(TreeNode* root) {
    return depth(root, false);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(3);
    cout << minDepth(root) << endl;
    cout << minDepth_w(root) << endl;
    deleteTree(root);
    return 0;
}
