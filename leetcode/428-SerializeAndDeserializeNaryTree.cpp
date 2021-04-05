#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 297-SerializeAndDeserializeBinaryTree
// preorder traversal, '#' for nullptr, need save size of children
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
    void se(Node* root, string& res) {
        if (!root) res += "#";
        else {
            res += to_string(root->val) + " ";
            res += to_string(root->children.size()) + " ";
            for (Node* child : root->children) se(child, res);
        }
    }

    Node* de(istringstream& in) {
        string val; in >> val;
        if (val == "#") return nullptr;
        Node* root = new Node(stoi(val));
        int n; in >> n;
        for (int i = 0; i < n; ++i) {
            root->children.push_back(de(in));
        }
        return root;
    }
public:
    string serialize(Node* root) {
        string s;
        se(root, s);
        return s;
    }

    Node* deserialize(string data) {
        istringstream in(data);
        return de(in);
    }
};

int main() {

}
