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

class Codec {
private:
    void preorder(TreeNode* root, stringstream& ssout) {
        if (root) {
            ssout << root->val << " ";
            preorder(root->left, ssout);
            preorder(root->right, ssout);
        } else ssout << "# ";
    }

    TreeNode* build(stringstream& ssin) {
        string val;
        ssin >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(ssin);
        root->right = build(ssin);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        stringstream ssout;
        preorder(root, ssout);
        return ssout.str();
    }

    TreeNode* deserialize(string data) {
        stringstream ssin(data);
        return build(ssin);
    }  
};

int main() {
    return 0;
}
