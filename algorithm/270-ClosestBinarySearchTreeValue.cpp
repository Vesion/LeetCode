#include <iostream>
#include <cmath> 
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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        while (root) {
            if (fabs(root->val-target) < fabs(res-target))
                res = root->val;
            if (root->val < target) root = root->right;
            else root = root->left;
        }
        return res;
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1500000000);
    root->left = new TreeNode(    1400000000);
    cout << s.closestValue(root, -1500000000.0) <<endl;;
    return 0;
}
