#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// The popular 'Serialize and Deserialize Binary Tree' problem
// Much discussion can be seen here:
// http://www.geeksforgeeks.org/serialize-deserialize-binary-tree/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 0 : preorder + inorder (or postorder + inorder), TLE
// serialize: concatenate preorder and inorder traversal;  deserialize: same with 105-ConstructBinaryTreeFromPreorderAndInorderTraversal
// here we only implement preorder+inorder
class Codec_pre_in {
private:
    void preorderTraversal(TreeNode* root, string& result) {
        if (root) {
            result += to_string(root->val) + " ";
            preorderTraversal(root->left, result);
            preorderTraversal(root->right, result);
        }
    }

    void inorderTraversal(TreeNode* root, string& result) {
        if (root) {
            inorderTraversal(root->left, result);
            result += to_string(root->val) + " ";
            inorderTraversal(root->right, result);
        }
    }

    TreeNode* build(vector<int>::iterator pre_start, vector<int>::iterator pre_end, 
            vector<int>::iterator in_start, vector<int>::iterator in_end) {
        if (pre_start == pre_end) return NULL;
        if (in_start == in_end) return NULL;

        TreeNode* root = new TreeNode(*pre_start);
        auto in_partition = find(in_start, in_end, *pre_start);
        auto left_size = distance(in_start, in_partition);

        root->left = build(next(pre_start), next(pre_start, left_size+1), in_start, in_partition);
        root->right = build(next(pre_start, left_size+1), pre_end, next(in_partition), in_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

public:
    string serialize(TreeNode* root) {
        string preorder, inorder;
        preorderTraversal(root, preorder);
        inorderTraversal(root, inorder);
        return preorder + "#" + inorder;
    }

    TreeNode* deserialize(string data) {
        auto partition = data.find('#');
        string preorder = data.substr(0, partition);
        string inorder = data.substr(partition+1, data.size()-partition-1);
        vector<int> pre_v, in_v;
        int val;
        istringstream pre(preorder); while (pre >> val) pre_v.push_back(val);
        istringstream in(inorder); while (in >> val) in_v.push_back(val);
        return buildTree(pre_v, in_v);
    }
};


// Solution 1 : use only preorder and mark nullptr with '#', with help of sstream, we flies!
//             e.g.         1
//                         / \
//                        2   3      ==>    "1 2 4 # # # 3 # 5 # #"
//                       /     \
//                      4       5
class Codec {
private:
    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        } else out << "# ";
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
public:
    string serialize(TreeNode* root) {
        ostringstream out;    
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec c;
    string data = c.serialize(root);
    cout << data << endl;
    c.deserialize(data);
    return 0;
}
