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


// Similar to 108-ConvertSortedArrayToBinarySearchTree
class Solution {
public:
    vector<int> vals;
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        inorder(root);
        return construct(0, vals.size());
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* construct(int lower, int upper) {
        if (lower >= upper) return nullptr;
        int mid = lower + (upper-lower)/2;
        TreeNode* root = new TreeNode(vals[mid]);
        root->left = construct(lower, mid);
        root->right = construct(mid+1, upper);
        return root;
    }
};


// O(1) space with rotation, DSW algorithm
// https://leetcode.com/problems/balance-a-binary-search-tree/discuss/541785/C%2B%2BJava-with-picture-DSW-O(n)orO(1)

class Solution {
public:
    int makeVine(TreeNode *grand, int cnt = 0) {
        auto n = grand->right;
        while (n != nullptr) {
            if (n->left != nullptr) {
                auto old_n = n;
                n = n->left;
                old_n->left = n->right;
                n->right = old_n;
                grand->right = n;
            } else {
                ++cnt;
                grand = n;
                n = n->right;
            }
        }
        return cnt;
    }
    void compress(TreeNode *grand, int m) {
        auto n = grand->right;
        while (m-- > 0) {
            auto old_n = n;
            n = n->right;
            grand->right = n;
            old_n->right = n->left;
            n->left = old_n;
            grand = n;
            n = n->right;
        }
    }
    TreeNode* balanceBST(TreeNode *root) {
        TreeNode grand;
        grand.right = root;
        auto cnt = makeVine(&grand);
        int m = pow(2, int(log2(cnt + 1))) - 1;
        compress(&grand, cnt - m);
        for (m = m / 2; m > 0; m /= 2) compress(&grand, m);
        return grand.right;
    }
};


int main() {
    return 0;
}
