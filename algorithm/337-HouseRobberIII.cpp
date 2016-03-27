#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Obviously, this problem has 'optimal structre' : 
//      if we want to rob maximum amount money from current node (rooted at 'root'), we surely want to do the same to its left and right subtree.
// As a result, we should calculate with bottom-up.
//
// the function rob(root) return the maximum amount of money that we can rob for the binary tree rooted at "root"; 
//      1. termination condition: if 'root' if NULL, we return 0
//      2. recurrence: I. if 'root' is robbed, its two children nodes cannot be robbed, but its four grandchildren nodes can be robbed;
//                     II. if 'root' is not robbed, its two children can be robbed.
//         we just need to return maximum of above two scenarios


// Solution 0 : naive, TLE
int rob_naive(TreeNode* root) {
    if (!root) return 0; // case 1 
    int do_robbed = root->val +  // case 2 I
        (root->left ? rob_naive(root->left->left) + rob_naive(root->left->right) : 0 ) + 
        (root->right ? rob_naive(root->right->left) + rob_naive(root->right->right) : 0);
    int no_robbed = rob_naive(root->left) + rob_naive(root->right); // case 2 II
    return max(do_robbed, no_robbed);
}


// Solution 1 : memoization, trivial, 40ms
// In Solution 0, we only consider 'optimal structure', another big problem has not been solved, 'overlapping of the subproblems'.
// So we use memo method to deal with it.
int rob_memo(TreeNode* root, unordered_map<TreeNode*, int>& memo) {
    if (!root) return 0;
    if (memo.count(root)) return memo[root];
    int do_robbed = root->val +  // case 2 I
        (root->left ? rob_memo(root->left->left, memo) + rob_memo(root->left->right, memo) : 0 ) + 
        (root->right ? rob_memo(root->right->left, memo) + rob_memo(root->right->right, memo) : 0);
    int no_robbed = rob_memo(root->left, memo) + rob_memo(root->right, memo); // case 2 II
    int result = max(do_robbed, no_robbed);
    memo[root] = result;
    return result;
}

int rob_memo(TreeNode* root) {
    unordered_map<TreeNode*, int> memo;
    return rob_memo(root, memo);
}


// Solution 2 : bottom-up with more information, skillful, 20ms
// In each subproblem, we calculate two things, one for maximum money if we rob this node, one for maximum money if we don't rob this node.
vector<int> robSub(TreeNode* root) {
    if (!root) return {0, 0};
    auto left = robSub(root->left);
    auto right = robSub(root->right);
    vector<int> result(2, 0);
    result[0] =  max(left[0], left[1]) + max(right[0], right[1]); // do not rob root
    result[1] = root->val + left[0] + right[0]; // rob root
    return result;
}

int rob(TreeNode* root) {
    auto result = robSub(root);
    return max(result[0], result[1]);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << rob_naive(root) << endl;
    cout << rob_memo(root) << endl;
    cout << rob(root) << endl;
    return 0;
}
