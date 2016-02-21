#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void printPreorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// similiar to binary search
TreeNode* build(vector<int>& nums, int left, int right) {
    if (left >= right) return NULL;
    int mid = left + (right-left)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = build(nums, left, mid);
    node->right = build(nums, mid+1, right);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    auto root = sortedArrayToBST(nums);
    printPreorder(root);
    cout << endl;
    deleteTree(root);
    return 0;
}
