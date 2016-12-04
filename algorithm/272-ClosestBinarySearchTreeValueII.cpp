#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Solution 1 : inorder traversal, maintain a window of size k, O(n)
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        inorder(root, target, res, k);
        return res;
    }

    void inorder(TreeNode* root, double target, vector<int>& res, int k) {
        if (root) {
            inorder(root->left, target, res, k);
            if ((int)res.size() == k) {
                if (fabs(root->val-target) < fabs(res.front()-target)) res.erase(res.begin());
                else return; // if current node is further, it's successors are no neeed to consider
            }
            res.push_back(root->val);
            inorder(root->right, target, res, k);
        }
    }
};


// Solution 2 : use stack to maintain predecessors and successors, O(k*logn)
// https://discuss.leetcode.com/topic/23151/o-logn-java-solution-with-two-stacks-following-hint/13



int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    s.closestKValues(root, 0.00, 1);
    return 0;
}
