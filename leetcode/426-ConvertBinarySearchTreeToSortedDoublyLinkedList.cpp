#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Inorder traverse
class Solution {
public:
    Node* first = nullptr;
    Node* prev = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        inOrder(root);
        prev->right=first;
        first->left=prev;
        return first;
    }
    void inOrder(Node* root){
        if(!root) return;
        inOrder(root->left);
        if(!first) first = root;
        if(prev){
            prev->right= root;
            root->left = prev;
        }
        prev = root;
        inOrder(root->right);
    }
};


int main() {

}