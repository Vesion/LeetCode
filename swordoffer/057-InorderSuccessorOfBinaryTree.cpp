#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int val) : val(val), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    TreeNode* GetNext(TreeNode* node)
    {
        if (!node) return NULL;
        if (node->right) {
            TreeNode* res = node->right;
            while (res->left) res = res->left;
            return res;
        } else {
            TreeNode* res = node->parent;
            while (res && res->left != node) {
                node = res;
                res = res->parent;
            }
            return res;
        }
    }
};


int main() {
    return 0;
}
