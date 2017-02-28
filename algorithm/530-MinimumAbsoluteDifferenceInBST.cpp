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

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> st;
        TreeNode *cur = root, *pre = NULL;
        int res = INT_MAX;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                if (pre) res = min(res, cur->val-pre->val);
                pre = cur;
                cur = cur->right;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
