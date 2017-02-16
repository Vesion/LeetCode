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

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start == end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid);
        root->right = build(nums, mid+1, end);
        return root;
    }
};


int main() {
    return 0;
}
