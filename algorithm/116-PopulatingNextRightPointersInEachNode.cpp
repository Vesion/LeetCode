#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void deleteTree(TreeLinkNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// Solution 0 : level order traversal, TLE!
// use level order traversal to store level, then connect them. Not constant space, and slow.
void connect_levelorder(TreeLinkNode *root) {
    if (!root) return;
    queue<TreeLinkNode*> q;
    q.push(root);
    TreeLinkNode* it;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            it = q.front();
            q.pop();
            if (!q.empty()) it->next = q.front();
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
        }
    }
}

// Solution 1 : iterative, use constant space, top-down
void connect_it(TreeLinkNode* root) {
    while (root) {
        TreeLinkNode* left = root->left;
        while (root) {
            if (root->left && root->right)
                root->left->next = root->right;
            if (root->right && root->next)
                root->right->next = root->next->left;
            root = root->next;
        }
        root = left;
    }
}

// Solution 2 : recursive, top-down too, skillful
void connect_re(TreeLinkNode* node, TreeLinkNode* sibling) {
    if (!node) return;
    node->next = sibling;
    connect_re(node->left, node->right);
    if (sibling)
        connect_re(node->right, sibling->left);
    else
        connect_re(node->right, NULL);
}
void connect_re(TreeLinkNode* root) {
   connect_re(root, NULL);
}

int main() {
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    connect(root);

    deleteTree(root);
    return 0;
}
