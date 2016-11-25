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


// Similar to 094-BinaryTreeInorderTraversal
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
        int num = cur->val;
        cur = cur->right;
        return num;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    BSTIterator it(root);
    cout << it.next() << endl;
    return 0;
}

