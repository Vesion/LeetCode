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

// Similar to 095-UniqueBinarySearchTreesII
// generate Catalan numbers
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n&1 == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        vector<TreeNode*> res;
        for (int i = 2; i <= n; i += 2) {
            for (TreeNode* left : allPossibleFBT(i-1)) {
                for (TreeNode* right : allPossibleFBT(n-i)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
