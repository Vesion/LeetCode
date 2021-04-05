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

// Reconstruct a BST with the give array as preorder sequence.

// Solution 1 : trivial, insert nodes one by one, O(nlogn)
class Solution_1 {
public:
    TreeNode* construct(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (int& val : preorder) root = insert(root, val);
        return root;
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }
};


// Solution 2 : recursively with lower and upper bound, O(n)
class Solution {
public:
    TreeNode* construct(vector<int>& preorder) {
        int cur = -1; // start form -1, means havn't read any value yet
        return helper(preorder, cur, INT_MIN, INT_MAX);
    }

    TreeNode* helper(vector<int>& preorder, int& cur, int lower, int upper) {
        ++cur; // try to read in a new value
        if (cur >= (int)preorder.size()) return NULL;
        if (preorder[cur] < lower || preorder[cur] > upper) { // if the new isn't in valid range, put cur back
            --cur;
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[cur]);
        root->left = helper(preorder, cur, lower, root->val);
        root->right = helper(preorder, cur, root->val, upper);
        return root;
    }
};


void print(TreeNode* root) {
    if (!root) {
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main() {
    Solution s;
    vector<int> preorder = {10, 6, 8, 12, 11};
    auto root = s.construct(preorder);
    print(root);
    return 0;
}
