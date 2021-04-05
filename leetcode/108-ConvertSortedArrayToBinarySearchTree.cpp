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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int begin, int end) {
        if (begin == end) return nullptr;
        int mid = begin + (end-begin)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, begin, mid);
        root->right = build(nums, mid+1, end);
        return root;
    }
};


int main() {
    return 0;
}
