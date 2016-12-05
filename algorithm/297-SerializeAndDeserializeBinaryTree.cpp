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
public:
    string serialize(TreeNode* root) {
        string res;
        se(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return de(in);
    }

private:
    void se(TreeNode* root, string& res) {
        if (!root)
            res += "# ";
        else {
            res += to_string(root->val) + " ";
            se(root->left, res);
            se(root->right, res);
        }
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
};


int main() {
    return 0;
}

