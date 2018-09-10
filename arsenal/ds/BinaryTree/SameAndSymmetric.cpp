#include <iostream>
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


// Determine if two trees are same / symmetric


// same
bool isSame(TreeNode* p, TreeNode* q) {
    return (!p && !q)
            || (p && q && isSame(p->left, q->left) && isSame(p->right, q->right));
}


// symmetric
bool isSymmetric(TreeNode* p, TreeNode* q) {
    return (!p && !q)
            || (p && q && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
}


int main() {
    return 0;
}
