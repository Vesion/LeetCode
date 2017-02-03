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

// Solution 1 : trivial, traverse whole BST and count each number's occurrence, O(n) space


// Solution 2 : inorder traversal, maintain maxCount and candidate mode set, pseudo-O(1) space
//      e.g. 1, 2, 3, ..., n, n
//      our candidate mode set will grow to O(n)
class Solution_2 {
public:
    vector<int> findMode(TreeNode* root) {
        int count = 0;
        int maxCount = 0;
        int pre = INT_MIN;
        vector<int> res;
        inorder(root, pre, count, maxCount, res);
        return res;
    }
    
    void inorder(TreeNode* root, int& pre, int& count, int& maxCount, vector<int>& res) {
        if (!root) return;
        inorder(root->left, pre, count, maxCount, res);
        if (root->val == pre) ++count;
        else count = 1;
        if (count >= maxCount) {
            if (count > maxCount) res.clear();
            res.push_back(root->val);
            maxCount = count;
        }
        pre = root->val;
        inorder(root->right, pre, count, maxCount, res);
    }
};


// Solution 3 : two inorder passes, first for finding out maxCount, second for collecting modes, real O(1) space
// https://discuss.leetcode.com/topic/77335/proper-o-1-space
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
    Solution s;
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->left->right = new TreeNode(8);
    auto r = s.findMode(root);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

