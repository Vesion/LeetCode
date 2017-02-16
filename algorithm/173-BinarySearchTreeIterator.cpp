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

// Inorder traversal with stack
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode* cur;

public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    bool hasNext() {
        return cur || !st.empty();
    }

    int next() {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top(); st.pop();
        int res = cur->val;
        cur = cur->right;
        return res;
    }
};


int main() {
    return 0;
}
