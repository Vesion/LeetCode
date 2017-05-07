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

// Solution 1 : brute-force, O(n*m) time
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return isSameTree(s, t) || (s && (isSubtree(s->left, t) || isSubtree(s->right, t)));
    }
    
    bool isSameTree(TreeNode* a, TreeNode* b) {
        return (!a && !b) || (a && b && a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right));
    }
};


// Solution 2 : serialization, O(n+m) time, O(n+m) space
class Solution_2 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return serialize(s).find(serialize(t)) != string::npos; // assume string.find() takes linear time
    }

    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    void serialize(TreeNode* root, string& res) {
        if (root) {
            res += " " + to_string(root->val);
            serialize(root->left, res);
            serialize(root->right, res);
        } else res += " #";
    }
};


int main() {
    return 0;
}
