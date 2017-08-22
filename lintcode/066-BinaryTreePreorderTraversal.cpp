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
    vector<int> result;

    vector<int> preorderTraversal(TreeNode *root) {
        if (root) {
            result.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return result;
    }  
};

int main() {
    Solution s;
    return 0;
}
