#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Because this is a perfect tree, just go through the whole tree, for each node, set its left and right child's next pointer

// Solution 1 : recursive
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect(root->left);
        connect(root->right);
    }
};


// Solution 2 : iterative
class Solution_2 {
public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        while (root->left) {
            TreeLinkNode* cur = root;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            root = root->left;
        }
    }
};


int main() {
    return 0;
}
