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

class Solution {
public:
    TreeNode* str2tree(string s) {
        int i = 0;
        return build(s, i);
    }
    
    TreeNode* build(string& s, int& i) {
        int n = s.size();
        if (i >= n) return NULL;
        int val = 0, sign = 1;
        if (s[i] == '-') { sign = -1; ++i; }
        while (i < n && isdigit(s[i])) val = val*10 + s[i++]-'0';
        TreeNode* root = new TreeNode(sign*val);
        if (i < n && s[i] == '(') {
            ++i;
            root->left = build(s, i);
            ++i;
        }
        if (i < n && s[i] == '(') {
            ++i;
            root->right = build(s, i);
            ++i;
        }
        return root;
    }
};


int main() {
    return 0;
}
