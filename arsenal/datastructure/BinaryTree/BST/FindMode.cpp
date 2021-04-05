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

// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

// two inorder passes, first for finding out maxCount, second for collecting modes, real O(1) space
class Solution {
public:
    int pre, count, maxCount;
    vector<int> res;

    vector<int> findMode(TreeNode* root) {
        pre = count = maxCount = 0;
        getMaxCount(root);
        pre = count = 0;
        collectModes(root);
        return res;
    }

    void getMaxCount(TreeNode* root) {
        if (!root) return;
        getMaxCount(root->left);
        if (root->val == pre) ++count;
        else count = 1;
        maxCount = max(maxCount, count);
        pre = root->val;
        getMaxCount(root->right);
    }

    void collectModes(TreeNode* root) {
        if (!root) return;
        collectModes(root->left);
        if (root->val == pre) ++count;
        else count = 1;
        if (count == maxCount) res.push_back(root->val);
        pre = root->val;
        collectModes(root->right);
    }
};


int main() {
    return 0;
}

