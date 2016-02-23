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
// 相比于116，新增一个prev指针，来记录该层之前的结点
void connect_it(TreeLinkNode* root) {
    while (root) {
        TreeLinkNode* next = NULL;
        TreeLinkNode* prev = NULL;
        while (root) { // fill this level
            if (!next) next = root->left ? root->left : root->right; // find the first node in next level
            if (root->left) {
                if (prev) prev->next = root->left;
                prev = root->left;
            }
            if (root->right) {
                if (prev) prev->next = root->right;
                prev = root->right;
            }
            root = root->next;
        }
        root = next; // go to next level
    }
}

int main() {
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);
    connect_it(root);

    deleteTree(root);
    return 0;
}
