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

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        if (root->left) {
            root->left->next = root->right;
            root->right->next = root->next ? root->next->left : nullptr;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

int main() {
    return 0;
}
