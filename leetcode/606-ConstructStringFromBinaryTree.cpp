#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        string res;
        preorder(root, res);
        res.erase(0, 1);
        res.pop_back();
        return res;
    }

    void preorder(TreeNode* root, string& res) {
        res += "(";
        if (root) {
            res += to_string(root->val);
            if (root->left || root->right) {
                preorder(root->left, res);
                if (root->right) preorder(root->right, res);
            }
        }
        res += ")";
    }
};


int main() {
    return 0;
}
