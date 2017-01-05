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

// All O(n) solutions will get TLE


// Solution 1 : check if it is a perfect tree recursively, O((logn)^2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        int left_height = 0, right_height = 0;
        for (TreeNode* p = root; p; p = p->left) ++left_height; // height of path along left
        for (TreeNode* p = root; p; p = p->right) ++right_height; // height of path along right
        if (left_height == right_height) return (1<<left_height) - 1; // it's a perfect tree
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// Solution 2 : divide and conquer with max height, O((logn)^2)
class Solution_2 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int max_height = 0, right_max_height = 0;
        for (TreeNode* p = root; p; p = p->left) ++max_height; // max height, e.g. height of path along left
        for (TreeNode* p = root->right; p; p = p->left) ++right_max_height; // max height of right subtree
        if (max_height == right_max_height+1) return 1 + (1<<(max_height-1))-1 + countNodes(root->right); // left subtree is a perfect tree
        else return 1 + countNodes(root->left) + (1<<(max_height-2))-1; // right subtree is a perfect tree
        //                 here use max_height-2, because right_max_height-1 might be negative
    }
};


// Solution 3 : count the lowest level's nodes only, the fastest, O(h^2), 72ms
// first check the right most child of the current node's left child. If this child is exist, we know that there may be more nodes on the right side of the tree. So we move the current node to it's right child. And repeat until we reach the lowest level.
class Solution_3 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height = 0;
        for (TreeNode* p = root; p; p = p->left) ++height;
        int count = 0;
        TreeNode* p = root;
        int level = height - 2;
        while (level >= 0) {
            TreeNode* left = p->left;
            for (int i = 0; i < level; ++i) left = left->right;
            if (left) {
                p = p->right;
                count += (1 << level);
            }
            else p = p->left;
            --level;
        }
        if (p) ++count;
        return (1 << (height-1)) - 1 + count;
    }
};


int main() {
    return 0;
}

