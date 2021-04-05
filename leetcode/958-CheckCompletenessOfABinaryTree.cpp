#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        int n = count(root);
        return check(root, 1, n);
    }

    bool check(TreeNode* root, int id, int n) {
        if (!root) return true;
        if (id > n) return false;
        return check(root->left, id*2, n) && check(root->right, id*2+1, n);
    }

    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
};

int main() {

}