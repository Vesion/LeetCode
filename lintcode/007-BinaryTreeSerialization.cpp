#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void se(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << " ";
            se(root->left, out);
            se(root->right, out);
        } else {
            out << "# ";
        }
    }

    string serialize(TreeNode *root) {
        ostringstream out;
        se(root, out);
        return out.str();
    }


    TreeNode* de(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = de(in);
        root->right = de(in);
        return root;
    }

    TreeNode *deserialize(string data) {
        istringstream in(data);
        return de(in);
    }    
};

int main() {
    Solution s;
    return 0;
}
