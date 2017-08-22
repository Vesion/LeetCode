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
        if (!root) return 0;
        int res = root->val;
        while (root) {
            if (fabs(root->val-target) < fabs(res-target)) res = root->val;
            if (root->val > target) root = root->left;
            else root = root->right;
        }
        return res;
    }
};


int main() {
    return 0;
}
