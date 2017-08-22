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
    int k1, k2;

    void search(TreeNode* root) {
        if (root) {
            search(root->left);
            if (root->val >= k1 && root->val <= k2) result.push_back(root->val);
            search(root->right);
        }
    }

    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        this->k1 = k1, this->k2 = k2;
        search(root);
        return result;
    }    
};

int main() {
    Solution s;
    return 0;
}
