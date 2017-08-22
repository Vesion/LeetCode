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
        deque<int> res;
        inorder(root, target, k, res);
        return vector<int>(res.begin(), res.end());
    }
    
    void inorder(TreeNode* root, double target, int k, deque<int>& res) {
        if (!root) return;
        inorder(root->left, target, k, res);
        if ((int)res.size() < k) res.push_back(root->val);
        else {
            if (fabs(root->val-target) < fabs(res.front()-target)) {
                res.pop_front();
                res.push_back(root->val);
            } else return;
        }
        inorder(root->right, target, k, res);
    }
};


// Solution 2 : use stack to maintain predecessors and successors, O(k*logn)
// First find the closest node to target, then find node's k-1 predecessor/successor nodes



int main() {
    return 0;
}
