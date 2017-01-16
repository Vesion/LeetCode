#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;


// Use the method in 297-SerializeAndDeserializeBinaryTree is trivial
// because it generates lots of '#' and is not very compact.
//
// We can build a BST only with its preorder sequence by inserting values one by one, it is O(nlogn)
// Can we be faster?
// Use lower and upper bound when build the tree
//      serialize : encode every non null node by preorder traversal, O(n)
//      deserialize: we can pass by the lower bound and upper bound to know the boundary of a subtree, O(n)

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        se(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return de(in, INT_MIN, INT_MAX);
    }

private:
    void se(TreeNode* root, string& res) {
        if (root) {
            res += to_string(root->val) + " ";
            se(root->left, res);
            se(root->right, res);
        }
    }

    TreeNode* de(istringstream& in, int lower, int upper) {
        string val;
        auto it = in.tellg();
        in >> val;
        if (val.empty() || in.eof()) return NULL;
        int num = stoi(val);
        if (num < lower || num > upper) {
            in.seekg(it);
            return NULL;
        }
        TreeNode* root = new TreeNode(num);
        root->left = de(in, lower, num);
        root->right = de(in, num, upper);
        return root;
    }
};


int main() {
    return 0;
}
