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

// Solution 1 : recursive
class Solution {
public:
    void connect(TreeLinkNode *root) {
        dfs(root, NULL);
    }

    void dfs(TreeLinkNode* root, TreeLinkNode* sibling) {
        if (!root) return;
        root->next = sibling;
        dfs(root->left, root->right);
        if (sibling) dfs(root->right, sibling->left);
        else dfs(root->right, NULL);
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
    Solution s;
    return 0;
}

